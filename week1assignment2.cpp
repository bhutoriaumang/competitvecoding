#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector <int> v(n,0);
    int x=0,y=0;
    for(int i=1;i<=n;i++){
        v[x]=1;
        x+=i;
        x%=n;
    }
    for(int i=0;i<n;i++)
        v[0]&=v[i];
    if(v[0]==0)
        cout<<"NO\n";
    else
        cout<<"YES\n";
}

/*

a a a
b a a
a b a
b a a
a b a

x a a a
a x a a
a a a x
a a x a

x a a a a
a x a a a
a a a x a
a x a a a
x a a a a

x a a a a a
a x a a a a
a a a x a a
x a a a a a
a a a a x a
a a a x a a
a a x a a a


*/