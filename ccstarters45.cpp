#include <bits/stdc++.h>
using namespace std;

#define MAXN   1000001
int spf[MAXN];

int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);   
}

void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;
 
    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
long long int getFactorization(int x)
{
    vector<int> ret;
    long long int sum = 0;
    while (x != 1)
    {
        sum+=(spf[x]);
        x = x / spf[x];
    }
    return sum;
}

int main(){
    sieve();
    int T;
    cin>>T;
    while(T-->0){
        int n,q;
        cin>>n>>q;
        while(q-->0){
            int x,y;
            cin>>x>>y;
            int a = gcd(x,y);
            x = x/a;
            y = y/a;
            long long int ans = getFactorization(x)+getFactorization(y);
            cout<<ans<<endl;
        }
    }
}