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
        string x = s.substr(0,n/2);
        string y = s.substr(n/2);
        if(n%2)
            y = y.substr(1);
        int c=0;
        for(int i=0;i<x.length();i++){
            int f=0;
            while(i<(x.length()) && x[i]!=y[y.length()-1-i]){
                f=1;
                i++;
            }
            if(f)
                c++;
        }
        if(c>1)
            cout<<"No\n";
        else
            cout<<"Yes\n";
    }
}