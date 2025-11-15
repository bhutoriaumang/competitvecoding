/*

Problem Tags: ['brute force', 'implementation', 'strings'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        string s;
        cin>>s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        if(s=="yes")
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}