#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector <long long int> v(s.length());
    v[0] = 0;
    for(int i=1;i<s.length();i++){
        v[i] = v[i-1];
        if(s[i-1]==s[i] && s[i]=='v')
            v[i]+=1;
    }
    long long int ans=0;
    for(int i=0;i<s.length();i++){
        if(s[i]=='o')
            ans+= v[i]*(v[s.length()-1]-v[i]);
    }
    cout<<ans<<endl;
}