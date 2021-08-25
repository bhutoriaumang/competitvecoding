#include </Users/bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T-->0){
	    int n;
	    cin>>n;
	    vector <long long int> v(n),x;
	    for(auto &i : v)
	        cin>>i;
	    sort(v.begin(),v.end());
        if(n==1){
            cout<<"1\n";
            continue;
        }
	    int c = 0;
	    for(int i=0;i<n-1;i++){
            if(v[i]==-1)
                c++;
	        while(i<n && v[i]==v[i+1]){
                if(v[i]==-1)
                    c++;
	            i++;
            }
	        x.push_back(v[i]);
	    }
	    if(v[n-1]!=v[n-2])
	        x.push_back(v[n-1]);
        n = x.size();
        if(n==1 && (x[0]*x[0])==x[0]){
            cout<<"1\n";
            continue;
        }
        else if(n==1){
            cout<<"0\n";
            continue;
        }
        if(n==3)
        {
	        //Case 1: -x 0 1
            if(v[v.size()-1]<=1 && v[v.size()-1>=0] && x[0]<-1 && x[1]==0 && (v[0]*v[1])==v[0] && n==3){
            cout<<"1\n";
            continue;
            }
            //Case 2:  0 1 x
            if(x[0]==0 && x[1]==1 && x[2]>1 && (v[v.size()-1]*v[v.size()-2])==v[v.size()-1] && n==3){
                cout<<"1\n";
                continue;
            }
        }
        //Case 3: -1....-1 0 1
        if(n==2 && v[0]==0 && v[v.size()-1]==1){
            cout<<"1\n";
            continue;
        }
        if(x[0]==-1 && c>1 && x[n-1]==1){
            cout<<"1\n";
            continue;
        }
	    //Case 4: -1 0
        if(x[0]==-1 && c==1 && x[n-1]<=1 && n<=3){
            cout<<"1\n";
            continue;
        }
        cout<<"0\n";
	}
	return 0;
}
