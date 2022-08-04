#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector <long long int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int ans = 0;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            long long int a = v[i]^v[j];
            a = 2*a;
            long long int b = v[i]+v[j];
            if(a==b)
                ans++;
        }
    }
    cout<<ans<<endl;
}

/*

1 2 2 8

1 3 1 9
8 9 11 9
2 10 11 9
2 0 8 9

a ab abc abcd abcde
e ea eab eabc eabcd
d de dea deab deabc
c cd cde cdea cdeab
b bc bcd bcde bcdea

a ab abc abcd abcde
e a ab abc abcd
d e a ab abc
c d e a ab 

*/