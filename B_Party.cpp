/*

Problem Tags: ['brute force', 'graphs'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,m;
        cin>>n>>m;
        vector <int> v(n),c(n,0);
        vector < pair <int,int> > x(n);
        int s = 0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            x[i].first = i+1;
            x[i].second = 1e5;
            s+=v[i];
        }
        for(int i=0;i<m;i++){
            int a,b;
            cin>>a>>b;
            x[a-1].second = min(x[a-1].second,v[b-1]);
            x[b-1].second = min(x[b-1].second,v[a-1]);
            c[a-1]++;
            c[b-1]++;
        }
        // cout<<s<<endl;
        // for(int i=0;i<n;i++)
        //     cout<<x[i].first<<" "<<x[i].second<<" : "<<c[i]<<endl;
        int tp=m,ans=0;
        for(int i=0;i<n;i++){
            // cout<<ans<<endl;
            if(tp%2==0)
                break;
            if(c[i]%2==1)
                ans = max(ans,s-v[i]);
            else if(c[i]>0)
                ans = max(ans,s-v[i]-x[i].second);
            // cout<<ans<<endl;
        }
        if(ans!=0)
            ans = s-ans;
        cout<<ans<<endl;
        // cout<<endl;
    }
}