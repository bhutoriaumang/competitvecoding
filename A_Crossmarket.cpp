/*

Problem Tags: ['constructive algorithms', 'greedy', 'math'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,m;
        cin>>n>>m;
        if(n==1 && m==1){
            cout<<"0\n";
            continue;
        }
        else if(n==1){
            cout<<(m)<<endl;
            continue;
        }
        int ans = (n) + (m) + min(m-2,n-2);
        cout<<ans<<endl;
    }
}