/*

Problem Tags: ['bitmasks', 'math'] 

*/

#include <bits/stdc++.h>
using namespace std;
long long int m = 1000000000 + 7;

long long int convert(long long int n, long long int k){
    string s = "";
    long long int ans = 0,t = 1;
    while(k>0){
        s = ((k%2)?"1":"0") + s;
        k/=2;
    }
    for(int i=s.length()-1;i>=0;i--){
        if(s[i]=='1')
            ans = ((ans%m) + (t%m))%m;
        t = ((t%m)*(n%m))%m;
    }
    return ans;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n,k;
        cin>>n>>k;
        if(n==2){
            cout<<k<<endl;
            continue;
        }
        cout<<convert(n,k)<<endl;
    }
}