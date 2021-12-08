#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    int m = 0,c=0,l=0,r=1;
    while(r<n){
        if(s[r]!=s[l])
            c++;
        if(c>k){
            c--;
            if(s[l]!=s[l+1]){
                c = (r-l) - c;
                
            }
        }

    }
    cout<<m<<endl;
}