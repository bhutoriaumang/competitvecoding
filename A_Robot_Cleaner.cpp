#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,m,a1,a2,b1,b2;
        cin>>n>>m>>a1>>b1>>a2>>b2;
        int x=1,y=1,ans=0;
        while(a1!=a2 && b1!=b2){
            if(a1==n)
                x=-x;
            if(b1==m)
                y=-y;
            a1+=x;
            b1+=y;
            ans++;
        }
        cout<<ans<<endl;
    }
}