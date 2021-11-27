#include </Users/bits/stdc++.h>
using namespace std;

long long int minimum(long long int n,long long int k){
    long long int x = n-k;
    long long int c = min(n-1,k);
    if(x>1){
        c+= ((2+x)*(x-1))/2;
    }
    return c;
}

long long int maximum(long long int n,long long int v){
    return (n*(n-1))/2;
}

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        long long int n,v;
        cin>>n>>v;
        cout<<maximum(n,v)<<" "<<minimum(n,v)<<endl;
    }
}