#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <long long int> v(n+1);
        long long int x=0;
        for(int i=0;i<=n;i++){
            cin>>v[i];
            x = x^v[i];
        }
        vector <long long int> b;
        if(n%2==1){
            int f = 0;
            for(int i=0;i<=n;i++){
                if(f==0 && v[i]==x){
                    f=1;
                    continue;
                }
                b.push_back(v[i]^x);
            }
        }
        else{
            for(int i=0;i<n;i++){
                b.push_back(v[i]^v[n]);
            }
        }
        sort(b.begin(),b.end());
        for(int i=0;i<n;i++)
            cout<<b[i]<<" ";
        cout<<endl;
    }
}

/*

a b c d
a b c
b c d
a c d
a b d

abcd
abc
bcd
acd
abd

1 2 4 8

7
13
11
14
15

10 12 9 8

100
100

111

a b
a
b

(a^b).a.b
aba ^ abb

*/