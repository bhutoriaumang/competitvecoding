#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    // int a[n+1][n+1];
    vector < vector <int> > a;
    int f[n+1],vis[n+1];
    for(int i=0;i<=n;i++){
        vector <int> temp(1,0);
        a.push_back(temp);
        f[i] = -1;
        vis[i] = 0;
    }
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    queue <int> q;
    q.push(1);
    while(!q.empty()){
        int i = q.front();
        int d = -1;
        q.pop();
        vis[i] = 1;
        if(f[i]!=-1)
            d = 1-f[i];
        else{
            for(int j=1;j<a[i].size();j++){
                if(f[a[i][j]]!=-1){
                    d = f[a[i][j]];
                    break;
                }
            }
        }
        if(d==-1)
            d = 0;
        f[i] = 1-d;
        for(int j=1;j<a[i].size();j++){
            if(vis[a[i][j]]==0)
                q.push(a[i][j]);
            f[a[i][j]] = d;
        }
    }
    long long int a1=0,a2=0;
    for(int i=1;i<=n;i++){
        if(f[i])
            a1++;
        else
            a2++;
    }
    long long int s = (a1*a2);
    cout<<(s-(long long int)(n-1))<<endl;
}