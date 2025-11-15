#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<long long int> p,pp;

void SieveOfEratosthenes(long long int n)
{
    n+=1;
    long long int prime[n + 1];
    for(long long int i=0;i<n+1;i++)
        prime[i] = 0;
 
    for (long long int j = 2; j<= n; j++)
    {
        if (prime[j] == 0)
        {
            for (long long int i = j * j; i <= n; i += j)
                prime[i] = 1;
        }
    }
    p.push_back(0);
    p.push_back(0);
    for(long long int i=2;i<=n;i++){
        if(prime[i]==0){
            p.push_back(1);
            pp.push_back(i);
        }
        else{
            p.push_back(0);
        }
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    SieveOfEratosthenes(n);
    for(int i=1;i<pp.size();i++){
        int t = pp[i-1]+pp[i]+1;
        if(p[t]==1)
            k--;
    }
    if(k>0)
        cout<<"NO\n";
    else
        cout<<"YES\n";
}