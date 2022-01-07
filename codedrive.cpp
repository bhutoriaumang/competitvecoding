#include </Users/bits/stdc++.h>
using namespace std;

#define int long long int
#define endl           "\n"
#define mod            1000000007
#define nitin          ios_base::sync_with_stdio(false); cin.tie(nullptr)

const int N = 400001;
int fact[N];
int fact_inv[N];

int power(int x, int y, int p) {
    int res = 1;
    x = x % p;
    while (y > 0) {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

int modi(int a, int m) {
    return power(a, m - 2, m);
}

void pre() {
    fact[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % mod;
    }
    fact_inv[N - 1] = modi(fact[N - 1], mod);
    for (int i = N - 2; i >= 0; i--) {
        fact_inv[i] = (fact_inv[i + 1] * (i + 1)) % mod;
    }
}

int ncr(int n, int r) {
    if (r > n)
        return 0;
    return (fact[n] * ((fact_inv[r] * fact_inv[n - r]) % mod)) % mod;
}

int32_t main(){
    nitin;
    pre();
    int n,m;
    cin>>n>>m;
    vector <int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    int p = 0;
    for(int i=0;i<n;i++){
        if(v[i]>m)
            p++;
    }
    if(m<n){
        cout<<"0\n";
        exit(0);
    }
    p=n-p;
    int ans = ncr(m,n)*fact[n];
    ans%=mod;
    for(int j=1;j<=p;j++){
        int val = ncr(p,j);
        val*=ncr(m-j,n-j);
        val%=mod;
        val*=fact[n-j];
        val%=mod;
        if(j%2)
            ans-=val;
        else
            ans+=val;
        ans%=mod;
        ans+=mod;
        ans%=mod;
    }
    cout<<ans<<endl;
}