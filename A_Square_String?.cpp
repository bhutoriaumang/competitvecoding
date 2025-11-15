#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        string s;
        cin>>s;
        if(s.substr(0,s.length()/2)==s.substr(s.length()/2))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}