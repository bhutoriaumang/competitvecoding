/*

Problem Tags: ['number theory'] 

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

vector<int> p;

void SieveOfEratosthenes(int n)
{
    int prime[n + 1];
    for(int i=0;i<n+1;i++)
        prime[i] = 0;
 
    for (int p = 2; p<= n; p++)
    {
        if (prime[p] == 0)
        {
            for (int i = p + p; i <= n; i += p)
                prime[i]++;
        }
    }
    for(int i=2;i<=n;i++){
        if(prime[i]==2){
            p.push_back(i);
        }
    }
}

int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"0\n";
        exit(0);
    }
    SieveOfEratosthenes(n);
    cout<<p.size()<<endl;
}