#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        string s;
        cin>>s;
        vector <int> a(3,0),v(3,0);
        int f = 1;
        for(int i=0;i<s.length();i++){
            if(s[i]=='r')
                a[0] = 1;
            else if(s[i]=='R'){
                if(a[0]==0){
                    f = 0;
                    break;
                }
                v[0] = 1;
            }
            else if(s[i]=='g')
                a[1] = 1;
            else if(s[i]=='G'){
                if(a[1]==0){
                    f = 0;
                    break;
                }
                v[1] = 1;
            }
            else if(s[i]=='b')
                a[2] = 1;
            else if(s[i]=='B'){
                if(a[2]==0){
                    f = 0;
                    break;
                }
                v[2] = 1;
            }
        }
        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}