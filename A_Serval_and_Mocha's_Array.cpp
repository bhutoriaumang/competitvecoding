/*

Problem Tags: ['brute force', 'math', 'number theory'] 

*/

#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int prime(int x){
    for(int i=2;i<x;i++){
        if(x%i==0)
            return 0;
    }
    return 1;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int a=0,b=1;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(gcd(v[a],v[b]) > gcd(v[i],v[j])){
                    a=i;
                    b=j;
                }
            }
        }
        swap(v[0],v[a]);
        swap(v[1],v[b]);
        int x = v[0],f=1;
        for(int i=1;i<n;i++){
            x = gcd(x,v[i]);
            if(x>(i+1)){
                f=0;
                break;
            }
        }
        if(f)
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}