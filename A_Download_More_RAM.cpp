/*

Problem Tags: ['brute force', 'greedy', 'sortings'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,k;
        cin>>n>>k;
        vector < pair <int,int> > v(n);
        for(int i=0;i<n;i++)
            cin>>v[i].first;
        for(int i=0;i<n;i++)
            cin>>v[i].second;
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++){
            if(v[i].first>k)
                break;
            k+=v[i].second;
        }
        cout<<k<<endl;
    }
}