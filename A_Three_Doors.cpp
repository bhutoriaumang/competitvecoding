#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int x,a,b,c;
        cin>>x>>a>>b>>c;
        vector <int> v,f(3,0);
        v.push_back(a);
        v.push_back(b);
        v.push_back(c);
        if(f[x-1]==0){
            f[x-1]=1;
            if(v[x-1]!=0){
                if(f[v[x-1]-1]==0){
                    f[v[x-1]-1]=1;
                    if(v[v[x-1]-1]!=0){
                        if(f[v[v[x-1]-1]-1]==0){
                            f[v[v[x-1]-1]-1]=1;
                        }
                    }
                }
            }
        }
        if(f[0]+f[1]+f[2]==3)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}