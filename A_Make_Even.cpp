#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        string s;
        cin>>s;
        int x = (int)(s[s.length()-1]) - 48;
        if(x%2==0){
            cout<<"0\n";
            continue;
        }
        x = -1;
        for(int i=0;i<s.length();i++){
            int d = (int)(s[i]) - 48;
            if(d%2==0){
                if(i==0)
                    x = 1;
                else
                    x = 2;
                break;
            }
        }
        cout<<x<<endl;
    }
}