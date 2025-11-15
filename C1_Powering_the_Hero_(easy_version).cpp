#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        priority_queue <long long int> v;
        long long int ans = 0;
        for(long long int i=0;i<n;i++){
            long long int x;
            cin>>x;
            if(x==0 && !v.empty()){
                ans+=v.top();
                v.pop();
            }
            else
                v.push(x);
        }
        cout<<ans<<endl;
    }
}