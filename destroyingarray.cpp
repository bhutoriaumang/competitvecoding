#include <bits/stdc++.h>
using namespace std;

class DSU{
    public:
    vector <long long int> x,rank,setsum,visited;
    long long int num,maximum;
    DSU(int n,vector <long long int> v){
        x.assign(n,0);
        setsum.assign(n,0);
        for(int i=1;i<n;i++){
            setsum[i] = v[i-1];
            x[i] = i;
        }
        rank.assign(n,0);
        visited.assign(n,-1);
        num = n;
        maximum = 0;
    }
    long long int findMax(){
        // long long int m = -1;
        // for(int i=1;i<setsum.size();i++){
        //     if(visited[i]!=-1 && (m==-1 || setsum[i]>m))
        //         m = setsum[i];
        // }
        // return m;
        return maximum;
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
        setsum[b]+=setsum[a];
        maximum = max(setsum[b],maximum);
        maximum = max(setsum[a],maximum);
        num--;
    }
};

int main(){
    int n;
    cin>>n;
    vector <long long int> a(n),v(n);
    for(auto &i : a)
        cin>>i;
    for(auto &i : v)
        cin>>i;
    reverse(v.begin(),v.end());
    if(n==1){
        cout<<"0\n";
        exit(0);
    }
    DSU set(n+1,a);
    vector <long long int> ans;
    ans.push_back(0);
    set.visited[v[0]] = 1;
    set.maximum = set.setsum[v[0]];
    for(int i=1;i<n-1;i++){
        // if(i>99996){cout<<endl;
        // cout<<endl;
        // for(int i=1;i<=n;i++)
        //     cout<<set.x[i]<<"\t"<<set.rank[i]<<"\t"<<set.setsum[i]<<"\t"<<set.visited[i]<<endl;}
        // cout<<endl;
        ans.push_back(set.findMax());
        // cout<<ans.back()<<"\t"<<i<<"\t"<<v[i]<<endl;
        // cout<<endl;
        set.visited[v[i]] = 1;
        set.maximum = max(set.maximum,set.setsum[v[i]]);
        if(set.visited[v[i]-1]==1)
            set.Union(v[i]-1,v[i]);
        if (v[i]!=(n) && set.visited[v[i]+1]==1)
            set.Union(v[i],v[i]+1);
        // if(i>99994){
        //     cout<<set.x[4540-1]<<"\t"<<set.rank[4540-1]<<"\t"<<set.setsum[4540-1]<<"\t"<<set.visited[4540-1]<<endl;
        //     cout<<set.x[4540]<<"\t"<<set.rank[4540]<<"\t"<<set.setsum[4540]<<"\t"<<set.visited[4540]<<endl;
        //     cout<<set.x[4540+1]<<"\t"<<set.rank[4540+1]<<"\t"<<set.setsum[4540+1]<<"\t"<<set.visited[4540+1]<<endl;
        //     cout<<endl;
        //     cout<<set.x[70649-1]<<"\t"<<set.rank[70649-1]<<"\t"<<set.setsum[70649-1]<<"\t"<<set.visited[70649-1]<<endl;
        //     cout<<set.x[70649-1]<<"\t"<<set.rank[70649-1]<<"\t"<<set.setsum[70649-1]<<"\t"<<set.visited[70649]<<endl;
        //     cout<<set.x[70649+1]<<"\t"<<set.rank[70649+1]<<"\t"<<set.setsum[70649+1]<<"\t"<<set.visited[70649+1]<<endl;
        //     cout<<set.x[43409-1]<<"\t"<<set.rank[43409-1]<<"\t"<<set.setsum[43409-1]<<"\t"<<set.visited[43409-1]<<endl;
        //     cout<<set.x[43409-1]<<"\t"<<set.rank[43409-1]<<"\t"<<set.setsum[43409-1]<<"\t"<<set.visited[43409]<<endl;
        //     cout<<set.x[43409+1]<<"\t"<<set.rank[43409+1]<<"\t"<<set.setsum[43409+1]<<"\t"<<set.visited[43409+1]<<endl;
        //     cout<<set.x[42140-1]<<"\t"<<set.rank[42140-1]<<"\t"<<set.setsum[42140-1]<<"\t"<<set.visited[42140-1]<<endl;
        //     cout<<set.x[42140-1]<<"\t"<<set.rank[42140-1]<<"\t"<<set.setsum[42140-1]<<"\t"<<set.visited[42140]<<endl;
        //     cout<<set.x[42140+1]<<"\t"<<set.rank[42140+1]<<"\t"<<set.setsum[42140+1]<<"\t"<<set.visited[42140+1]<<endl;
        //     cout<<endl;
        //     cout<<endl;
        // }
    }
    ans.push_back(set.findMax());
    for(int i=0;i<ans.size();i++)
        cout<<ans[ans.size()-1-i]<<endl;
}

/*

17
12 9 17 5 0 6 5 1 3 1 17 17 2 14 5 1 17
3 7 5 8 12 9 15 (13 11 14 6 16 17 1 10 2 4)

12 9 (17) 5 (0) 6 (5 1 3) 1 17 (17) 2 14 5 1 17


*/