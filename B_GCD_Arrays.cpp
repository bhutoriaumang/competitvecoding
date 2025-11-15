/*

Problem Tags: ['greedy', 'math', 'number theory'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int l,r,k;
        cin>>l>>r>>k;
        if(l==r && l==1){
            cout<<"NO\n";
            continue;
        }
        else if(l==r && l!=1){
            cout<<"YES\n";
            continue;
        }
        long long int n = (r-l+1)/2;
        if(l%2==1 && r%2==1)
            n++;
        if((n)<=k)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}