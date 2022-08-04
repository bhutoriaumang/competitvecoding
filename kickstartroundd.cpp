#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        int n,m;
        cin>>n>>m;
        vector <int> v(n);
        vector < vector <int> > x(m,vector <int>());
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        int ans = 0;
        for(int i=1;i<m;i++)
            ans+=2*v[n-i];
        int u = n-m+1;
        if(u&1)
            ans += 2*v[u/2];
        else
            ans += ((int)v[u/2] + (int)(v[u/2 - 1]));
        cout << "Case #" << cas << ": " << (ans/2);
	    if(ans&1)cout << ".5";
	    cout << '\n';
    }
}