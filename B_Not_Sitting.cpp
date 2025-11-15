#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,m;
        cin>>n>>m;
        vector <int> v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int x = max(i,n-i-1) + max(j,m-j-1);
                v.push_back(x);
            }
        }
        sort(v.begin(),v.end());
        for(int i=0;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
}