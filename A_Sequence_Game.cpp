/*

Problem Tags: ['brute force', 'sortings'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        long long int m1=pow(10,9), m2=-pow(10,9);
        for(long long int i=0;i<n;i++) {
            long long int x;
            cin>>x;
            m1 = min(m1,x);
            m2 = max(m2,x);
        }
        long long int x;
        cin>>x;
        if (x<m1 || x>m2) {
            cout<<"NO\n";
        } else {
            cout<<"YES\n";
        }

    }
}