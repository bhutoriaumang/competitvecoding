#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,k;
        cin>>n>>k;
        vector <long long int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        int ans = 0;
        for(int i=1;i<n-1;i++){
            if(v[i]> (v[i-1]+v[i+1]))
                ans++;
        }
        int x1 = 0;
        if(k==1)
            x1 = ceil((double)(n-2)/2.0);
        ans = max(ans,x1);
        cout<<ans<<endl;
    }
}