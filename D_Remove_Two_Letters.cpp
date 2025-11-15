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
        int ans = n-1;
        for(int i=0;(i+2)<(n);i++){
            // cout<<s[i]<<" "<<s[i+2]<<endl;
            if(s[i]==s[i+2])
                ans--;
        }
        cout<<ans<<endl;
    }
}

/*

abcdef

cdef
adef
abef
abcf
abcd

x3x4x5x6
x1x4x5x6
x1x2x5x6
x1x2x3x6
x1x2x3x4

x1x2x3

x3
x1

x1==x3

x1x2x3x4

x3x4
x1x4
x1x2

x1x2==x3x4
x2==x4
x1==x3

x1x2x3x4x5

x3x4x5
x1x4x5
x1x2x5
x1x2x3

x1x2==x4x5
x1==x3
x2==x4
x3==x5

x1x2x3x4x5x6

x3x4x5x6
x1x4x5x6
x1x2x5x6
x1x2x3x6
x1x2x3x4

x1x2x3x4==x3x4x5x6
x1==x3
x2==x4
x3==x5
x4==x6

*/