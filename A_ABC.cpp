/*

Problem Tags: ['implementation'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int c1=0,c2=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')
                c1++;
            else
                c2++;
        }
        if(c1>1 || c2>1)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
}