#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    T = 1;
    while(T-->0){
        long long int n,l,k;
        cin>>n>>l>>k;
        vector < vector <long long int> > v(n,vector <long long int> (2,0));
        for(int i=0;i<n;i++)
            cin>>v[i][0];
        for(int i=0;i<n;i++)
            cin>>v[i][1];
        sort(v.begin(),v.end());
        long long int ans = 0;
        vector <long long int> temp;
        temp.push_back(l);
        temp.push_back(0);
        v.push_back(temp);
        for(int i=0;i<n;i++){
            ans += v[i][1]*(v[i+1][0]-v[i][0]);
        }
        while(k-->0){
            long long int x = ans,ind=-1;
            for(int i=1;i<v.size()-1;i++){
                long long int aa = (v[i+1][0]-v[i][0])*v[i][1] + v[i-1][1]*(v[i][0]-v[i-1][0]);
                long long int bb = (v[i+1][0]-v[i-1][0])*v[i-1][1];
                if(x>(ans+bb-aa))
                    ind=i;
                x = min(x,ans+bb-aa);
            }
            if(x>=ans)
                break;
            v.erase(v.begin()+ind,v.begin()+ind+1);
            ans = x;
        }
        cout<<ans<<endl;
    }
}