#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        long long int a,b,c,k;
        cin>>a>>b>>c;
        k = abs(b-a)*2;
        if(max(a,max(b,c)) <= k)
            cout<<((c>(k/2))?(c-(k/2)):(c+(k/2)))<<"\n";
        else
            cout<<"-1\n";
    }
}