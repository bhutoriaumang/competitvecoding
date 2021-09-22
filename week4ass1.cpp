#include </Users/bits/stdc++.h>
using namespace std;

class DSU{
    public:
    vector <long long int> x,rank;
    DSU(int n){
        x.assign(n,0);
        for(int i=0;i<n;i++){
            x[i] = i;
        }
        rank.assign(n,0);
    }
    long long int findSet(int i){
        if(x[i]==i)
            return i;
        else
        {
            x[i] = findSet(x[i]);
            return x[i];
        }
    }
    bool isSameSet(int i, int j){
        return (findSet(i)==findSet(j));
    }
    void Union(int i,int j){
        if(isSameSet(i,j))
            return;
        int a = findSet(i);
        int b = findSet(j);
        if(rank[a]>rank[b])
            swap(a,b);
        x[a] = b;
        if(rank[a]==rank[b])
            rank[b]++;
    }
};

int main(){
    int n,q;
    cin>>n>>q;
    DSU nodes(n);
    for(int i=0;i<q;i++){
        int t,u,v;
        cin>>t>>u>>v;
        if(t==0){
            nodes.Union(u,v);
        }
        else
            cout<<((nodes.isSameSet(u,v))?"1":"0")<<endl;
    }
}