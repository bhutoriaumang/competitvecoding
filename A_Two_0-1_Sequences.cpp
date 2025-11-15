#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,m;
        cin>>n>>m;
        string a,b;
        cin>>a>>b;
        int x=n-1,y=m-1;
        int f=1;
        while(y>0){
            if(b[y]!=a[x]){
                f=0;
                break;
            }
            x--;y--;
        }
        if(y==0){
            int fl=0;
            while(x>=0){
                if(a[x]==b[y]){
                    fl=1;
                    break;
                }
                x--;
            }
            f = f&fl;
        }
        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}