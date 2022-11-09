#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    T=1;
    while(T-->0){
        int n,m;
        cin>>n>>m;
        vector <long long int> v(n),f(n,0),d(n,0);
        for(int i=0;i<n;i++)
            cin>>v[i];
        while(m-->0){
            long long int ii,x;
            cin>>ii>>x;
            ii--;
            v[ii] = x;
            int t = 0;
            for(int i=0;i<n;i++){
                f[i] = 1;
                t++;
                d[i]=t;
                while(i<(n-1) && v[i]==v[i+1]){
                    i++;
                    d[i]=t;
                }
                f[i]=1;
            }
            long long int ans = 0;
            
        }
    }
}