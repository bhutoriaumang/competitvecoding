#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,k;
        cin>>n>>k;
        vector < vector <int> > v(n+1,vector<int>());
        vector <int> check(n+1,-1);
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        if(n==1){
            cout<<"0\n";
            continue;
        }
        queue <int> q;
        for(int i=1;i<=n;i++){
            if(v[i].size()==1){
                q.push(i);
                check[i]=0;
            }
        }
        while(k-->0){
            if(q.size()==0)
                break;
            int x = q.size();
            while(x-->0){
                int t = q.front();
                q.pop();
                if(v[t].size()>1){
                    check[t] = -1;
                    continue;
                }
                else if(v[t].size()==0){
                    check[t] = 1;
                    continue;
                }
                v[v[t][0]].erase(remove(v[v[t][0]].begin(),v[v[t][0]].end(),t),v[v[t][0]].end());
                if(check[v[t][0]]==-1){
                    q.push(v[t][0]);
                    check[v[t][0]] = 0;
                }
                v[t].pop_back();
                check[t] = 1;
            }
        }
        int ans=n;
        for(int i=1;i<=n;i++){
            if(check[i]==1)
                ans--;
        }
        cout<<ans<<endl;
    }
}