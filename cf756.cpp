#include <bits/stdc++.h>
using namespace std;



int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        vector <long long int> v(n),p(n),x(n),a(n,0),ans;
        for(long long int i=0;i<n;i++)
            cin>>p[i];
        for(long long int i=0;i<n;i++)
            cin>>v[i];
        ans.push_back(0);
        x[v[0]-1] = 0;
        for(long long int i=1;i<n;i++){
            ans.push_back(ans[i-1]+ans[p[v[i]-1]-1]+1);
            x[v[i]-1] = ans[i];
        }
        long long int f = 1;
        for(long long int i=0;i<n;i++){
            if(x[i]<x[p[i]-1])
                f = 0;
        }
        if(f==0){
            cout<<"-1\n";
            continue;
        }
        for(long long int i=0;i<n;i++)
            cout<<x[i]<<" ";
        cout<<endl;
    }
}