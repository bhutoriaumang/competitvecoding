#include </Users/bits/stdc++.h>
using namespace std;

vector <int> levels;

void calc(vector < vector <int> > v,int x,int count){
    if(v[x].size()==0){
        levels.push_back(count);
        return;
    }
    for(int i=0;i<v[x].size();i++){
        v[v[x][i]].erase(remove(v[v[x][i]].begin(), v[v[x][i]].end(), x), v[v[x][i]].end());
        calc(v,v[x][i],count+1);
    }
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,m;
        cin>>n>>m;
        vector < vector <int> > v(n+1,vector <int> ());
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        levels.clear();
        calc(v,1,0);
        vector <long long int> x(m);
        long long int temp = 1;
        for(int i=0;i<m;i++){
            long long int t;
            cin>>t;
            x.push_back(t-temp+1);
            temp = t;
        }
        sort(levels.begin(),levels.end(),greater<int>());
        sort(x.begin(),x.end(),greater<long long int>());
        
    }
}