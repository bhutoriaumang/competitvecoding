#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n);
        vector < vector <int> > x(n+1,vector<int>());
        for(int i=0;i<n;i++){
            cin>>v[i];
            x[v[i]].push_back(i);
        }
        for(int i=1;i<=n;i++){
            int ans = 0;
            for(int j=0;j<x[i].size();j++){
                int s = 1;
                while(j<(x[i].size()-1) && (x[i][j+1]-x[i][j])%2==1){
                    s++;
                    j++;
                }
                ans = max(ans,s);
            }
            cout<<ans<<" ";
        }
        cout<<endl;
    }
}