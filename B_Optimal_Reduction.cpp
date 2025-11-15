/*

Problem Tags: ['constructive algorithms', 'sortings'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        vector <long long int> v(n);
        long long int m = 0;
        for(long long int i=0;i<n;i++){
            cin>>v[i];
            m = max(m,v[i]);
        }
        long long int a=v[0],b=v[n-1];
        vector <long long int> x(n),y(n);
        for(long long int i=0;i<n;i++){
            x[i] = a;
            a = max(a,v[i]);
        }
        for(long long int i=n-1;i>=0;i--){
            y[i] = b;
            b = max(b,v[i]);
        }
        long long int f = 1;
        for(long long int i=0;i<n;i++){
            if(x[i]>v[i] && y[i]>v[i]){
                f=0;
                break;
            }
        }
        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}