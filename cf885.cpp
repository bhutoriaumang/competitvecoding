#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,m,k;
        cin>>n>>m>>k;
        int x,y;
        cin>>x>>y;
        vector < pair <int,int> > v(k);
        for(int i=0;i<n;i++)
            cin>>v[i].first>>v[i].second;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int t = max(abs(x-i),abs(y-j));
                for(int l=0;l<k;l++){
                    int tt = max(abs(v[l].first-i),abs(v[l].second-j));
                    if(tt<=t)
                }
            }
        }
    }
}

/*


xxexxaxxxx
xxxxxaxxxx
xxxxxaxxxx
aaaaaaaaaa
xxxxxaxxxx
xxxxxaxxxx
xxxxxaxxxx
xxxxxaxxxx

b a a a
a a x a
a a a a


*/