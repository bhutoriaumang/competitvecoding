#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin>>n;
    long double x = log2(n);
    if(floor(x)==ceil(x))
        cout<<"TAK\n";
    else
        cout<<"NIE\n";
}