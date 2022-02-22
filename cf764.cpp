#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector <int> v(26,0);
        for(int i=0;i<n;i++){
            v[(int)s[i] - 97]++;
        }
        int cp=0,co=0;
        for(int i=0;i<26;i++){
            cp+=(v[i]/2);
            co+=(v[i]%2);
        }
        int ans = 2*(cp/k);
        co+= 2*(co%k);
        if(co>=k)
            ans++;
        cout<<ans<<endl;
    }
}