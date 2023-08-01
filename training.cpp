#include <bits/stdc++.h>
using namespace std;

map <long long int,long long int> m;

long long int calc(long long int x){
    if(x==1)
        return 1;
    else if(x==2)
        return 2;
    if(m.find(x-1)==m.end())
        m.insert(make_pair(x-1,calc(x-1)));
    if(m.find(x-2)==m.end())
        m.insert(make_pair(x-1,calc(x-2)));
    return m[x-1] + (x-1)*m[x-2];
}

int main(){
    long long int n;
    cin>>n;
    m.insert(make_pair(1,1));
    m.insert(make_pair(2,2));
    cout<<calc(n)<<endl;
}