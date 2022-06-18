#include <bits/stdc++.h>
using namespace std;

long long gcd(long long int a, long long int b)
{
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

long long lcm(int a, int b)
{
    return (a / gcd(a, b)) * b;
}

vector <long long int> printDivisors(long long int n)
{

    vector <long long int> v;
    for (long long int i=1; i<=sqrt(n); i++)
    {
        if (n%i == 0)
        {
            if (n/i == i)
                v.push_back(i);
 
            else{
                v.push_back(i);
                if(i!=1)
                    v.push_back(n/i);
            }
        }
    }
    return v;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        vector <long long int> v = printDivisors(n);
        long long int ans = 0;
        for(int i=0;i<v.size();i++){
            long long int x = v[i];
            long long int y = n-v[i];
            if(y%x==0)
                ans+=2;
            if(x==y)
                ans--;
        }
        cout<<ans<<endl;
    }
}