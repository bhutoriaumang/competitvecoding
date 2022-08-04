#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n,ans=0;
        cin>>n;
        queue <long long int> q;
        q.push(n);
        while(!q.empty()){
            long long int x = ceil((double)q.front()/2.0);
            long long int y = floor((double)q.front()/2.0);
            q.pop();
            ans += (x*y);
            if(x>1)
                q.push(x);
            if(y>1)
                q.push(y);
        }
        cout<<ans<<endl;
    }
}