#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int x,y;
        cin>>x>>y;
        vector <int> v;
        for(int i=x;i<=y;i++){
            int c=0,t=i;
            while(t<=y){
                c++;
                t+=t;
            }
            cout<<i<<" "<<c<<endl;
            v.push_back(c);
            if(i!=1){
                c=0;
                t=i;
                while(t<=y){
                    c++;
                    t*=i;
                }
                cout<<i<<" "<<c<<endl;
                if(c>1)
                    v.push_back(c);
            }
        }
        sort(v.begin(),v.end(),greater <int> ());
        int ans = 1;
        for(int i=0;i<v.size();i++){
            while(i<(v.size()-1) && v[i]==v[i+1]){
                ans++;
                i++;
            }
            cout<<v[i]<<" "<<ans<<endl;
            break;
        }
    }
}