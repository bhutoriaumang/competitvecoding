#include </Users/bits/stdc++.h>
using namespace std;

vector<pair <long long int,long long int> > subarr(vector<long long int> v,long long int n,long long int m){
    vector <pair <long long int,long long int> > ans;
    long long int s= 0;
    queue <long long int> q;
    for(int i=0;i<n;i++){
        s+=v[i];
        q.push(i);
        if(s>m){
            s-=v[q.front()];
            q.pop();
        }
        if(s%m==0){
            ans.push_back(make_pair(q.front(),i));
        }
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i].first<<"\t"<<ans[i].second<<endl;
    }
    return ans;
}

long long int check(long long int a, long long int b){
    vector <long long int> x,y;
    long long int c = 0;
    while(a>1){
        cout<<"HI\n";
        x.push_back(a%2);
        a/=2;
    }
    x.push_back(1);
    while(b>1){
        cout<<"HII\n";
        y.push_back(b%2);
        if(b%2)
            c++;
        b/=2;
    }
    y.push_back(1);
    int k = 0;
    while(k<min(x.size(),y.size())){
        if(x[k]!=y[k] && x[k]==1)
            return -1;
        k++;
    }
    return c;
}

int main() {
	int T;
	cin>>T;
	while(T-->0){
	    long long int n,m,mn=-1;
	    cin>>n>>m;
	    vector <long long int> v(n);
	    for(int i=0;i<n;i++)
	        cin>>v[i];
	    vector <pair <long long int,long long int> > ans = subarr(v,n,m);
	    for(int i=0;i<ans.size();i++){
	        long long int k = check(ans[i].first,ans[i].second);
            if(k!=-1)
                mn = (mn!=-1)?min(mn,k):k;
	    }
        cout<<mn<<endl;
	}
	return 0;
}
