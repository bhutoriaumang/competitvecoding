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
        // int f = 1;
        // if(s[0]=='W')
        //     f = 0;
        // vector <int> b,w;
        // for(int i=0;i<n-1;i++){
        //     int c = 1;
        //     while(i<n-1 && s[i]==s[i+1]){
        //         i++;
        //         c++;
        //     }
        //     if(s[i]=='B')
        //         b.push_back(c);
        //     else
        //         w.push_back(c);
        // }
        // if((n>1 && s[n-1]!=s[n-2]) || n==1){
        //     if(s[n-1]=='B')
        //         b.push_back(1);
        //     else
        //         w.push_back(1);
        // }
        // int ans = n;
        // for(int i=0;i<b.size();i++){
        //     if(b[i]>=k)
        //         ans = 0;
        // }
        int ans = n;
        int c = 0;
        for(int i=0;i<k;i++){
            if(s[i]=='W')
                c++;
        }
        ans = min(ans,c);
        for(int i=k;i<n;i++){
            if(s[i]=='W')
                c++;
            if(s[i-k]=='W')
                c--;
            ans = min(ans,c);
        }
        cout<<ans<<endl;
    }
}