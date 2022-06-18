#include <bits/stdc++.h>
using namespace std;

bool** dp;
bool ans = false;

void display(const vector<int>& v){
	for (int i = 0; i < v.size(); ++i)
		printf("%d ", v[i]);
	printf("\n");
}

void check(vector <int> x,vector <int> y,int s){
    sort(x.begin(),x.end());
    sort(y.begin(),y.end());
    int i=0,j=0,c=0;
    for(i=0;i<x.size();i++){
        if(x[i]==y[j]){
            j++;
            continue;
        }
        c+=x[i];
    }
    if(c==s && !ans){
        ans = true;
        cout<<"POSSIBLE\n";
        cout<<y.size()<<endl;
        display(y);
    }
}

void printSubsetsRec(vector <int> arr, int i, long long int sum, vector<int>& p, long long int s){
	if (i == 0 && sum != 0 && dp[0][sum]){
		p.push_back(arr[i]);
		if (arr[i] == sum)
			check(arr,p,s);
		return;
	}
	if (i == 0 && sum == 0){
        check(arr,p,s);
		return;
	}
	if (dp[i-1][sum]){
		vector<int> b = p;
		printSubsetsRec(arr, i-1, sum, b, s);
	}
	if (sum >= arr[i] && dp[i-1][sum-arr[i]]){
		p.push_back(arr[i]);
		printSubsetsRec(arr, i-1, sum-arr[i], p, s);
	}
}
void printAllSubsets(vector <int> arr, int n, long long int sum,long long int s){
	if (n == 0 || sum < 0)
	return;

	dp = new bool*[n];
	for (int i=0; i<n; ++i){
		dp[i] = new bool[sum + 1];
		dp[i][0] = true;
	}

	if (arr[0] <= sum)
	    dp[0][arr[0]] = true;
	for (int i = 1; i < n; i++){
		for (int j = 0; j < sum + 1; j++){
			dp[i][j] = (arr[i] <= j) ? dp[i-1][j] || dp[i-1][j-arr[i]] : dp[i - 1][j];
        }
    }
	if (dp[n-1][sum] == false){
		return;
	}
	vector<int> p;
	printSubsetsRec(arr, n-1, sum, p, s);
}

int main()
{
	int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        ans = false;
        int n;
        long long int x,y;
        double s1=0,s2=0,s=0;
        cin>>n>>x>>y;
        vector <int> v(n);
        for(int i=0;i<n;i++){
            v[i] = i+1;
            s+=v[i];
        }
        s1 = ((double)(x*s)/(double)(x+y));
        s2 = ((double)(y*s)/(double)(x+y));
        cout << "CASE #" << cas << ": ";
        if(floor(s1)==ceil(s1) && floor(s2)==ceil(s2))
            printAllSubsets(v,n,(long long int)s1,(long long int)s2);
        if(!ans)
            cout<<"IMPOSSIBLE\n";
    }
	return 0;
}
