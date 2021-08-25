#include </Users/bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimum(vector<long long int> vis, vector<long long int> dist,int n){
        int ind = -1;
        long long int x = 10000+1;
        for(int i=0;i<n;i++){
            if(vis[i]==0 && (dist[i]<x)){
                x = dist[i];
                ind = i;
            }
        }
        return ind;
    }
    
    int countPaths(int n, vector<vector<int> > &roads) {
        vector <vector <int> > x;
        for(int i=0;i<n;i++){
            vector <int> temp(n,-1);
            x.push_back(temp);
        }
        for(int i=0;i<n;i++){
            x[roads[i][0]][roads[i][1]] = roads[i][2];
            x[roads[i][1]][roads[i][0]] = roads[i][2];
        }
        vector <long long int> dist(n,10000+1),vis(n,0);
        dist[0] = 0;
        for(int i=0;i<n-1;i++){
            int j = minimum(vis,dist,n);
            cout<<i<<"\t"<<j<<"\n";
            vis[j] = 1;
            for(int k=0;k<n;k++){
                if(x[j][k]==-1)
                    continue;
                if(vis[k]==0 && dist[k]>(dist[j]+x[j][k])){
                    dist[k] = dist[j]+x[j][k];
                }
            }
        }
        return dist[n-1];
        
    }
};

int main(){
    int n,x;
    cin>>n>>x;
    vector< vector<int> > p;
    for(int i=0;i<x;i++){
        int a,b,c;
        cin>>a>>b>>c;
        vector <int> temp;
        temp.push_back(a);
        temp.push_back(b);
        temp.push_back(c);
        p.push_back(temp);
    }
    Solution s;
    cout<<s.countPaths(n,p)<<endl;
}

// [[0,6,7],[0,1,2],[1,2,3],[1,3,3],[6,3,3],[3,5,1],[6,5,1],[2,5,1],[0,4,5],[4,6,2]]