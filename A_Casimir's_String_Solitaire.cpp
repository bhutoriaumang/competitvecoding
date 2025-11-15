#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        string s;
        cin>>s;
        int k = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='B')
                k++;
        }
        if(k==(s.length()/2) && s.length()%2==0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}