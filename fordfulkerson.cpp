#include </Users/bits/stdc++.h>
using namespace std;
vector <int> p;

bool pathexists(vector <vector <int> > v,int n,int s,int t){
    queue <int> q;
    vector <bool> vis(n,false);
    q.push(s);
    p[s] = -1;
    vis[s] = true;
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0;i<n;i++){
            if(!vis[i] && v[x][i]>0){
                p[i] = x;
                vis[i] = true;
                if(i==t){
                    return true;
                }
                q.push(i);
            }
        }
    }
    return false;
}

int ford_fulkerson(vector <vector <int> > v,int n,int s,int t){
    vector < vector <int> > rv(n,vector <int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            rv[i][j] = v[i][j];
    }
    int maxflow=0;
    while(pathexists(rv,n,s,t)){
        int flow = rv[p[t]][t];
        int x = t;
        while(x!=s){
            int y = p[x];
            flow = min(flow,rv[y][x]);
            x = y;
        }
        x = t;
        while(x!=s){
            int y = p[x];
            rv[x][y]+=flow;
            rv[y][x]-=flow;
            x = y;
        }
        maxflow+=flow;
    }
    return maxflow;
}

int main(){
    int n,e;
    cout<<"Enter the number of vertices : ";
    cin>>n;
    p.assign(n,-1);
    vector < vector <int> > v(n,vector <int>(n,0));
    cout<<"Enter the number of edges : ";
    cin>>e;
    for(int i=0;i<e;i++){
        int x,y,d;
        cout<<"Enter the starting vertex, ending vertex and capacity of edge "<<(i+1)<<" : ";
        cin>>x>>y>>d;
        v[x][y] = d;
    }
    int s,t;
    cout<<"Enter the source vertex : ";
    cin>>s;
    cout<<"Enter the sink vertex : ";
    cin>>t;
    cout<<"The maxflow of the graph is : "<<ford_fulkerson(v,n,s,t)<<endl;
}