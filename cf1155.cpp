#include <bits/stdc++.h>
using namespace std;

long long int mod = 998244353;

long long int fact(long long int x){
    if(x==0)
        return 1;
    return ((x%mod) * (fact(x-1)%mod))%mod;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        string s;
        cin>>s;
        long long int ans = 1,count=0,f=0;
        for(long long int i=0;i<s.length();i++){
            long long int c=1;
            while(i<(s.length()-1) && s[i]==s[i+1]){
                c++;
                i++;
            }
            // cout<<c<<" ";
            if(c>1){
                ans = ((ans%mod)*((c%mod)*((c-1)%mod))%mod)%mod;
                count+=(c-1);
                f++;
            }
        }
        // cout<<endl;
        cout<<count<<" "<<((ans%mod) * (fact(f)%mod))%mod<<endl;
    }
}