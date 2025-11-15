#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n);
        vector < vector <int> > x(1000000,vector <int>());
        for(int i=0;i<n;i++){
            cin>>v[i];
            x[v[i]].push_back(i);
        }
        int ans = -1;
        for(int i=0;i<1000000;i++){
            if(x[i].size()<=1)
                continue;
            for(int j=0;j<x[i].size()-1;j++){
                ans = max(ans,x[i][j]+n-x[i][j+1]);
            }
        }
        cout<<ans<<endl;
    }
}