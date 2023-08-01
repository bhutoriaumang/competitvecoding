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
        if(n%3==1){
            cout<<"YES\n";
            continue;
        }
        vector <int> x(26,n),y(26,-1);
        for(int i=0;i<n;i++){
            if(i%3==0 && x[(int)s[i]-97]==n)
                x[(int)s[i]-97] = i;
            if((n-i-1)%3==0)
                y[(int)s[i]-97] = i;
        }
        int f=0;
        for(int i=0;i<26;i++){
            if(x[i]<y[i]){
                f=1;
                break;
            }
        }
        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}

/*


e e e
c d d d e
b b c c c
a a a a a

c c c
b b b b c
a a a a a

*/