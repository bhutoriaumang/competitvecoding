#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n,m,k,l1,l2;
        cin>>n>>m>>k;
        l1 = n-1;
        l2 = (n%2)?(n*((n-1)/2)):((n/2)*(n-1));
        k-=2;
        if(n==1 && m==0 && k>-1){
            cout<<"YES\n";
        }
        else if(n==1 && m==0 && k<=-1){
            cout<<"NO\n";
        }
        else if(m>l2 || m<l1)
            cout<<"NO\n";
        else if(m>=l1 && m<l2 && k>=2)
            cout<<"YES\n";
        else if(m==l2 && k>=1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}