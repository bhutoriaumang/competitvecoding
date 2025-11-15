#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int m = 1000000000 + 7;
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        long long int ans = 1;
        for(int i=3;i<=2*n;i++)
            ans = ((ans%m) * (i%m))%m;
        cout<<ans%m<<endl;
    }
}