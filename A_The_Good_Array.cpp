#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,k;
        cin>>n>>k;
        int ans = (int)ceil((double)n/(double)k);
        if((n-1)%k!=0)
            ans++;
        cout<<ans<<endl;
    }
}

// 1 0 0 0 0 1 0 0 0