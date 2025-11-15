#include <iostream>
#include <vector>
using namespace std;

vector<int> prime(1000000 + 1,1);

void SieveOfEratosthenes(int n)
{
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p]==1)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = 0;
        }
    } 
}

int main(){
    int n;
    cin>>n;
    SieveOfEratosthenes(n);
    for(int i=4;i<=(n/2);i++){
        if(prime[i]==0 && prime[n-i]==0){
            cout<<i<<" "<<n-i<<endl;
            break;
        }
    }
}