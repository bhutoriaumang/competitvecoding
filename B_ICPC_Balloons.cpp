#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector <int> v(26,0);
        for(int i=0;i<n;i++){
            if(v[(int)s[i] - 65]==0)
               v[(int)s[i] - 65]+=2;
            else
                v[(int)s[i] - 65]++; 
        }
        int ans = 0;
        for(int i=0;i<26;i++)
            ans+=v[i];
        cout<<ans<<endl;
    }
}