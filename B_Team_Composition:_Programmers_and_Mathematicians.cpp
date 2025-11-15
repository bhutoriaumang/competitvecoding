#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int a,b;
        cin>>a>>b;
        if(a>b){
            a = a+b;
            b = a-b;
            a = a-b;
        }
        long long int x = a,ans=0;
        x-= (b/3);
        ans+=(b/3);
        ans+=(x/4);
        x = (x%4) + (b%3);
        ans+=(x/4);
        x = max((long long int)0,x);
        ans = min(a,ans);
        cout<< ans<<endl;
    }
}