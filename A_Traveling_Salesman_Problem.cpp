/*

Problem Tags: ['geometry', 'greedy', 'implementation'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector < pair <int,int> > v(n);
        int maxx=0,minx=0,maxy=0,miny=0;
        for(int i=0;i<n;i++){
            cin>>v[i].first>>v[i].second;
            maxx = max(maxx,v[i].first);
            minx = min(minx,v[i].first);
            maxy = max(maxy,v[i].second);
            miny = min(miny,v[i].second);
        }
        vector <int> x;
        if(maxx>0)
            x.push_back(abs(maxx));
        if(minx<0)
            x.push_back(abs(minx));
        if(maxy>0)
            x.push_back(abs(maxy));
        if(miny<0)
            x.push_back(abs(miny));
        if(n==1){
            cout << (abs(minx)+maxx+abs(miny)+maxy)*2 << endl;
            continue;
        }
        sort(x.begin(),x.end());
        int ans = 0;
        for(int i=0;i<x.size();i++){
            // cout<<"HI\n";
            // cout<<i<<" "<<x.size()<<endl;
            // if(i==4)
            //     break;
            ans += x[i]*2;
            // cout<<x[i]<<" "<<ans<<endl;
        }
        cout << ans << endl;
    }
}