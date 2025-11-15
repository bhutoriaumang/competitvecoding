/*

Problem Tags: ['constructive algorithms', 'math'] 

*/

#include <bits/stdc++.h>
using namespace std;

long long int gcd(long long int a, long long int b)
{
    return b == 0 ? a : gcd(b, a % b);   
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n,l,r;
        cin>>n>>l>>r;
        vector <long long int> v(n);
        int f = 1;
        for(long long int i=1;i<=n;i++){
            long long int x = ceil((double)l/(double)i) * i;
            if(x<=r)
                v[i-1] = x;
            else{
                f=0;
                break;
            }
        }
        if(f){
            cout<<"YES\n";
            for(int i=0;i<n;i++)    
                cout<<v[i]<<" ";
            cout<<endl;
        }
        else
            cout<<"NO\n";
    }
}

/*

a b c

c - xb - ya
c = xb + ya = xza + ya = a(xz + y)
d = lc + mb

b - za = 0

*/