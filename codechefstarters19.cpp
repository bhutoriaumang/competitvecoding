#include </Users/bits/stdc++.h>
using namespace std;
long long int mod = 1000000007;
long long int binpow(long long int a, long long int b, long long int m) {
    a %= m;
    long long int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <long long int> v(n);
        vector <pair <long long int,long long int> > x;
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        long long int s = 0;
        for(int i=0;i<n-1;i++){
            long long int c = 1;
            s++;
            while(i<n-1 && v[i]==v[i+1]){
                c++;
                i++;
            }
            x.push_back(make_pair(v[i],c));
        }
        if(v[n-1]!=v[n-2]){
            x.push_back(make_pair(v[n-1],1));
            s++;
        }
        long long int ans = ((binpow(2,s,mod)%mod)-1)%mod;
        for(int i=0;i<x.size();i++){
            ans += ((binpow(2,s-1,mod)%mod - 1)*((x[i].second-1)%mod))%mod;
            ans += (x[i].second-1);
        }
        cout<<ans<<endl;
    }
}