/*

Problem Tags: ['constructive algorithms', 'number theory'] 

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<long long int> p;

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
    for(long long int i=2;i<=n;i++){
        if(prime[i]==0){
            p.push_back(1);
        }
        else
            p.push_back(2);
    }
}

int main(){
    long long int n;
    cin>>n;
    if(n<=2){
        cout<<"1\n";
    }
    else
        cout<<"2\n";
    SieveOfEratosthenes(n);
    for(long long int i = 0;i<p.size();i++)
        cout<<p[i]<<" ";
    cout<<endl;
}