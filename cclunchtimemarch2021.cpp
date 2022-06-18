#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,qu;
    cin>>n>>m>>qu;
    vector < vector <int> > v(n+1);
    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    queue < int > q;
    vector <int> x(n+1,0),y(n+1,0);
    for(int i=0;i<qu;i++){
        int query,t;
        cin>>query>>t;
        if(query==1){
            x[t] = 1;
            y[t] = 1;
            for(int j=0;j<v[t].size();j++){
                if(y[v[t][j]]==0){
                    q.push(v[t][j]);
                    y[v[t][j]]=1;
                }
            }
        }
        else if(query==3){
            if(x[t]==1)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else{
            while(t-->0 && q.size()>0){
                int size = q.size();
                while(size-->0){
                    int d = q.front();
                    q.pop();
                    x[d] = 1;
                    y[d] = 1;
                    for(int j=0;j<v[d].size();j++){
                        if(y[v[d][j]]==0){
                            q.push(v[d][j]);
                            y[v[d][j]]=1;
                        }
                    }
                }
            }
        }
    }
}