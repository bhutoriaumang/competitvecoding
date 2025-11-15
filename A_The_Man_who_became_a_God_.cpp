#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,k;
        cin>>n>>k;
        vector <int> v(n),x;
        for(int i=0;i<n;i++)
            cin>>v[i];
        int ans=0;
        for(int i=0;i<n-1;i++){
            x.push_back(abs(v[i]-v[i+1]));
            ans+=x.back();
        }
        sort(x.begin(),x.end(),greater<int>());
        for(int i=0;i<k-1;i++)
            ans-=x[i];
        cout<<ans<<endl;
    }
}