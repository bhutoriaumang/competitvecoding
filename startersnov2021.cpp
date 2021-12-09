#include </Users/bits/stdc++.h>
using namespace std;

bool prime[1000000 + 1];
void SieveOfEratosthenes()
{
    int n = 1000000;
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

int main(){
    int T;
    cin>>T;
    SieveOfEratosthenes();
    while(T-->0){
        int n,k;
        cin>>n>>k;
        if(k==(n-1)){
            cout<<"Yes\n";
            for(int i=2;i<=n;i++)
                cout<<i<<" ";
            cout<<endl;
            continue;
        }
        vector <int> x;
        x.push_back(1);
        for(int i=2;i<=n;i++){
            if(prime[i] && i*2>n)
                x.push_back(i);
        }
        if(x.size()<k && x.size()<(n-k))
            cout<<"No\n";
        else{
            cout<<"Yes\n";
            if(k<(n-k)){
                for(int i=0;i<min(k,(int)x.size());i++)
                    cout<<x[i]<<" ";
            }
            else{
                int f = 0;
                for(int i=1;i<=n;i++){
                    if(i==x[f])
                        f++;
                    else
                        cout<<i<<" ";
                    f = min(n-k-1,f);
                }
            }
            cout<<endl;
        }
    }
}