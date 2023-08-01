#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int fact(int x){
    return (x==0)?1:(x*fact(x-1));
}

int main() {
    int n,r;
    cin>>n>>r;
    cout<<fact(n)/(fact(r)*fact(n-r))<<endl;
    return 0;
}
