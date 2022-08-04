#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        long long int n,m,k;
        cin>>n>>m>>k;
        long long int maximum = 0;
        vector <long long int> v(k);
        for(long long int i=0;i<k;i++){
            cin>>v[i];
            maximum = max(maximum,v[i]);
        }
        if(maximum>=(n*m)){
            cout<<"Yes\n";
            continue;
        }
        if(n%2==1 && m%2==1){
            cout<<"No\n";
            continue;
        }
        long long int c1 = 0,c2=0;
        for(long long int i=0;i<k;i++){
            c1 += (v[i]/(n*2));
            c2 += (v[i]/(m*2));
        }
        if(n%2==1)
            c2=0;
        else if(m%2==1)
            c1=0;
        if((c1>0 && c1>=(m/2)) || (c2>0 && c2>=(n/2)))
            cout<<"Yes\n";
        else
            cout<<"No\n";
    }
}

/*

1 2 3
4 5 6
7 8 9


b b a
b a a
a a a


a a a b b
a a a b b
a a a b b
a a a b b
a a a b b

*/