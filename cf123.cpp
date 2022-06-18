#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    long long int mod = 998244353;
    cin>>T;
    while(T-->0){
        long long int n,m,k,q;
        cin>>n>>m>>k>>q;
        vector <pair <long long int,long long int> > v(q);
        vector <long long int> r(n+1,0),c(m+1,0);
        for(long long int i=0;i<q;i++){
            cin>>v[i].first>>v[i].second;
            r[v[i].first]++;
            c[v[i].second]++;
        }
        long long int count = 0;
        for(long long int i=0;i<q;i++){
            r[v[i].first]--;
            c[v[i].second]--;
            if(r[v[i].first]==0 || c[v[i].second]==0)
                count = (count+1)%mod;
        }
        cout<<(((count%mod)*(k%mod))%mod)<<endl;
    }
}
/*

10  20
11  22

11  11  22  22  22
11  12  20  21  22

11 12  11 12  22 21  22 21  22 21
11 22  11 22  22 11  22 11  22 11

01  02
11  22


1 2 3

10
11

22
21

23
33


*/