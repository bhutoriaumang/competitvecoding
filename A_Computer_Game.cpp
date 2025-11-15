/*

Problem Tags: ['brute force', 'dfs and similar', 'dp', 'implementation'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        string s1,s2;
        cin>>s1;
        cin>>s2;
        int f = 1;
        for(int i=0;i<n;i++){
            if(s1[i]=='1' && s2[i]=='1'){
                f = 0;
                break;
            }
        }
        if(!f || s2[n-1]=='1')
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
}