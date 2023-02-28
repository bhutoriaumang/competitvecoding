#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,m;
        cin>>n>>m;
        vector <int> v(n),f(1e5,0),ans(n,-1);
        for(int i=0;i<n;i++){
            v[n-1-i] = i+1;
            f[v[n-i-1]] = 1;
        }
        for(int i=0;i<m;i++){
            int x;
            cin>>x;
            
        }
        
    }
}