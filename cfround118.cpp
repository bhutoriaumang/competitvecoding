#include </Users/bits/stdc++.h>
using namespace std;
long long int mod = 998244353 ;

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
        vector <int> v(n),x,y;
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=0;i<n-1;i++){
            int c = 1;
            x.push_back(v[i]);
            while(i<n-1 && v[i]==v[i+1]){
                c++;
                i++;
            }
            y.push_back(c);
        }
        if(v[n-1]!=v[n-2]){
            x.push_back(v[n-1]);
            y.push_back(1);
        }
        vector <int> a(x.size(),0),b(x.size(),0);
        long long int c = 0;
        for(int i=0;i<x.size()-1;i++){
            cout<<i<<"\t"<<c<<endl;
            if(i<n-2 && x[i]==(x[i+2]-2)){
                if(a[i+1]==1 && a[i]==1)
                    c = (c%mod - (binpow(2,y[i+1]+y[i],mod)%mod - 1)%mod)%mod;
                else if(a[i]==1)
                    c = (c%mod - (binpow(2,y[i],mod)%mod - 1)%mod)%mod;
                else if(a[i+1]==1)
                    c = (c%mod - (binpow(2,y[i+1],mod)%mod - 1)%mod)%mod;
                a[i] = 1;
                a[i+1] = 1;
                a[i+2] = 1;
                c = (c%mod + (binpow(2,y[i]+y[i+1]+y[i+2],mod)%mod - 1)%mod )%mod;
            }
            else if(x[i]==(x[i+1]-2)){
                if(a[i]==1)
                    c = (c%mod - (binpow(2,y[i],mod)%mod - 1)%mod)%mod;
                if(a[i+1]==1)
                    c = (c%mod - (binpow(2,y[i+1],mod)%mod - 1)%mod)%mod;
                a[i] = 1;
                a[i+1] = 1;
                c = (c%mod + (binpow(2,y[i]+y[i+1],mod)%mod - 1)%mod )%mod;
            }
        }
        for(int i=0;i<x.size();i++){
            if(a[i])
                continue;
            cout<<i<<" "<<c<<endl;
            c = (c%mod + (binpow(2,y[i],mod)%mod - 1)%mod)%mod;
        }
        cout<<c<<endl;
    }
}