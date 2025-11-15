/*

Problem Tags: ['math', 'number theory'] 

*/

#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int gcd(int a, int b){
    if (b == 0)
        return a;
    return gcd(b, a % b);    
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n);
        int mi = 1000000;
        for(int i=0;i<n;i++){
            cin>>v[i];
            mi = min(mi,v[i]);
        }
        int k = 0;
        for(int i=0;i<n;i++){
            k = gcd(k,v[i]-mi);
        }
        if(k!=0)
            cout<<k<<endl;
        else
            cout<<"-1"<<endl;
    }
}