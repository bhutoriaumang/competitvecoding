#include </Users/bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    int t;
    cin>>t;
    while(t-->0){
        ll a,b,c,m;
        cin>>a>>b>>c>>m;
        ll p = (a/2) + (b/2) + (c/2);
        if(p<m){
            cout<<"NO\n";
            continue;
        }
        else if(p==m){
            cout<<"YES\n";
            continue;
        }
        
    }
}