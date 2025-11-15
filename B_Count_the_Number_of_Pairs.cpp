/*

Problem Tags: ['greedy', 'strings'] 

*/

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
        vector <int> x(26,0),y(26,0);
        for(int i=0;i<n;i++){
            if(s[i]>='A' && s[i]<='Z')
                x[(int)s[i] - 65]++;
            else
                y[(int)s[i] - 97]++;
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            ans+=min(x[i],y[i]);
            // cout<<i<<" : "<<x[i]<<" , "<<y[i]<<" "<<ans<<" ";
            int t = min(k,abs(x[i]-y[i])/2);
            // cout<<t<<endl;
            k-=t;
            ans+=t;
        }
        cout<<ans<<endl;
    }
}