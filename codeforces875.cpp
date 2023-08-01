#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> a(n),b(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        vector <int> aa = cal(a,n);
        vector <int> bb = cal(b,n);
        int ans = 0;
        for(int i=0;i<aa.size();i++)
            ans = max(ans,aa[i]+bb[i]);
        cout<<ans<<endl;
    }
}