/*

Problem Tags: ['constructive algorithms'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        if(v[0]!=n && v[n-1]!=n){
            cout<<"-1\n";
            continue;
        }
        int f = 0;
        vector<int> ans;
        if(v[0]==n)
            f = 1;
        for(int i=0;i<n;i++){
            if(v[i]==n)
                continue;
            ans.push_back(v[i]);
        }
        if(f)
            ans.push_back(n);
        reverse(ans.begin(),ans.end());
        if(!f)
            ans.push_back(n);
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
}