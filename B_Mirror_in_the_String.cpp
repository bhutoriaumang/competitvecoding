#include <bits/stdc++.h>
using namespace std;

string rev(string x){
    string w="";
    for(int i=0;i<x.length();i++)
        w = x[i]+w;
    return w;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int x = 1;
        for(int i=1;i<n;i++){
            if(s[i]<=s[i-1])
                x++;
            else
                break;
        }
        if(s.length()>1 && s[0]==s[1])
            x = 1;
        string a = s.substr(0,x);
        a = a+rev(a);
        cout<<a<<endl;
    }
}