#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,m;
        cin>>n>>m;
        vector <vector <int> > a;
        vector <int> vis(n+1,0),f(n+1,-1);
        for(int i=0;i<=n;i++){
            vector <int> temp(1,0);
            a.push_back(temp);
        }
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            a[x].push_back(y);
            a[y].push_back(x);
        }
        queue <int> q;
        q.push(1);
        f[1] = 0;
        while(!q.empty()){
            int i = q.front();
            vis[i] = 1;
            q.pop();
            for(int j=1;j<a[i].size();j++){
                if(f[a[i][j]]!=-1)
                    continue;
                f[a[i][j]] = 1-f[i];
                q.push(a[i][j]);
            }
        }
        vector <int> k1,k2;
        for(int i=1;i<=n;i++){
            if(f[i])
                k1.push_back(i);
            else
                k2.push_back(i);
        }
        cout<<min(k1.size(),k2.size())<<endl;
        if(k1.size()<k2.size()){
            for(int i=0;i<k1.size();i++)
                cout<<k1[i]<<" ";
            cout<<endl;
        }
        else{
            for(int i=0;i<k2.size();i++)
                cout<<k2[i]<<" ";
            cout<<endl;
        }
    }
}