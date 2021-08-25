#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int p = 0,t=0;
    for(int i=0;i<s.length();i++){
        int k = (int)s[i] - 97;
        t+= (abs(p-k)>13)?(26-abs(p-k)):abs(p-k);
        p = k;
        t++;
    }
    cout<<t<<"\n";
}