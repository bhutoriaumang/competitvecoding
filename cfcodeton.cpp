#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n,m;
        cin>>n>>m;
        vector <long long int> v(m),d;
        for(int i=0;i<m;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        // d.push_back(v[0]-1);
        // d.push_back(n-v[m-1]);
        for(int i=1;i<m;i++)
            d.push_back(v[i]-v[i-1]-1);
        long long int ans=m,x=0;
        if(v[0]==1 && v[m-1]!=n){
            d.push_back(n-v[m-1]);
        }
        else if(v[0]!=1 && v[m-1]==n){
            d.push_back(v[0]-1);
        }
        else if(v[0]!=1 && v[m-1]!=n){
            d.push_back(v[0]-1 + n-v[m-1]);
        }
        sort(d.begin(),d.end(),greater<long long int>());
        for(int i=0;i<d.size();i++){
            // cout<<x<<" "<<ans<<" "<<d[i]<<endl;
            ans += min(x+1,d[i]);
            if((x+1)==d[i])
                ans--;
            x+=4;
        }
        cout<<ans<<endl;
    }
}

/*

z x x z y
y y z z y y y

z x z y y
y z x z y y y

y y y
z x x z y

z y y
y z z y y

x z y y y y y y y z
z y y y z y y y y y y y z x x x x x x x

*/