#include </Users/bits/stdc++.h>
using namespace std;

class Nodes{
    public:
    vector <int> p,rank;
    vector <vector <int> > sum;
    Nodes(int n,vector < vector<int> > v){
        p.assign(n,0);
        vector <int> temp(1,-1);
        for(int i=1;i<n;i++){
            sum.push_back(v[i]);
            p[i] = i;
        }
        rank.assign(n,0);
    }

    int findSet(int i){
        if(p[i]==i)
            return i;
        p[i] = findSet(p[i]);
        return p[i];
    }

    int maximumPath(){
        vector <int> s(p.size(),0);
        for(int i=1;i<=sum.size();i++){
            s[findSet(i)]+= sum[i-1].back();
        }
        int m = s[0];
        for(int i=1;i<s.size();i++){
            m = max(s[i],m);
        }
        return m;
    }

    bool sameSet(int i, int j){
        return (findSet(i)==findSet(j));
    }

    void Union(int i,int j){
        if(sameSet(i,j))
            return;
        int x = findSet(i);
        int y = findSet(j);
        if(rank[x]>rank[y])
            swap(x,y);
        p[x] = y;
        if(rank[x]==rank[y])
            rank[y]++;
    }
};

int main(){
    int n,m,Q;
    cin>>n>>m>>Q;
    vector < vector<int> > a;
    vector < vector<int> > q;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        vector <int> temp(1,x);
        if(i==0)
            a.push_back(temp);
        a.push_back(temp);
    }
    vector <pair <int,int> > edges;
    vector <int> edgeval(m+1,1);
    edges.push_back(make_pair(-1,-1));
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        edges.push_back(make_pair(x,y));
    }
    for(int i=0;i<Q;i++){
        int x,y,z;
        cin>>x>>y;
        vector <int> temp;
        temp.push_back(x);
        temp.push_back(y);
        if(x==1){
            edgeval[y] = 0;
        }
        else{
            cin>>z;
            temp.push_back(x);
            a[y].push_back(z);
        }
        q.push_back(temp);
    }
    Nodes graph(n+1,a);
    for(int i=1;i<edges.size();i++){
        if(edgeval[i]==1)
            graph.Union(edges[i].first,edges[i].second);
    }
    vector <int> ans;
    for(int i=0;i<Q;i++){
        vector <int> qq = q.back();
        q.pop_back();
        ans.push_back(graph.maximumPath());
        if(qq.size()==3)
            graph.sum[qq[1]-1].pop_back();
        else
            graph.Union(edges[qq[1]].first,edges[qq[1]].second);
    }
    while(ans.size()>0){
        cout<<ans.back()<<endl;
        ans.pop_back();
    }
}