/*

Problem Tags: ['greedy', 'sortings'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        vector < priority_queue <long long int> > v(n+1,priority_queue <long long int>());
        for(long long int i=0;i<n;i++){
            long long int a,b;
            cin>>a>>b;
            v[a].push(b);
        }
        long long int ans=0;
        for(long long int i=1;i<=n;i++){
            long long int c=i;
            while(v[i].size()>0 && c-->0){
                ans+=v[i].top();
                v[i].pop();
            }
        }
        cout<<ans<<endl;
    }
}

// 1 0 0 0 0 1 0 0 0