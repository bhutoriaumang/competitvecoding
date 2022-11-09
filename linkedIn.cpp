#include <bits/stdc++.h>
using namespace std;

int main(){
    vector < vector <int> > v(arr.size(),vector <int> ());
    int n=arr.size();
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            if(arr[i]<arr[j])
                v[i].push_back(j);
        }
    }
    int ans=0;
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<v[i].size();j++)
            ans+=v[v[i][j]].size();
    }
    return ans;
}