#include </Users/bits/stdc++.h>
using namespace std;
# define lli long long int
vector <int> prime(100001,0);

void SieveOfEratosthenes()
{
    int n = 100000+1;
 
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == 0)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = 1;
        }
    }
}

vector <lli> printDivisors(lli n)
{
    vector <lli> fac;
    for (lli i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
                fac.push_back(i);
            else
            {
                fac.push_back(i);
                fac.push_back(n/i);
            }
        }
    }
    return fac;
}

lli maxPrimefac(lli n){
    lli maxprime = 2;
    while(n>1){
        if(n%maxprime==0)
            n/=maxprime;
        else
            maxprime++;
    }
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        lli n,a,b;
        cin>>n>>a>>b;
        if(a<=0 && b<=0){
            cout<<((n%2)?b:a)<<endl;
        }
        else if(a<0){
            lli ans = ((n%2)?b:a);
            if(printDivisors(n).size()==2){
                cout<<ans<<endl;
                continue;
            }
            
        }
    }
}