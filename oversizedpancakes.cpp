#include </Users/bits/stdc++.h>
using namespace std;

bool check(string s){
    for(int i=0;i<s.length();i++){
        if(s[i]=='-')
            return false;
    }
    return true;
}

int main(){
    int T;
    cin>>T;
    for(int cas = 1;cas<=T;cas++){
        string s;
        int k,c=0;
        cin>>s>>k;
        cout<<"Case #"<<cas<<": ";
        for(int i=0;i<=s.length()-k;i++){
            if(s[i]=='-'){
                c++;
                for(int j=0;j<k;j++)
                    s[i+j] = (s[i+j]=='+')?'-':'+';
            }
        }
        if(check(s))
            cout<<c<<"\n";
        else
            cout<<"IMPOSSIBLE\n";
    }
}