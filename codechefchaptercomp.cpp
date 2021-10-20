#include </Users/bits/stdc++.h>
using namespace std;
#define lli long long int

void display(queue <int> q){
    cout<<"Queue\t:\t";
    while(!q.empty()){
        cout<<q.front()<<"\t";
        q.pop();
    }
    cout<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,m,k;
        cin>>n>>m>>k;
        vector < vector <int> > v(n+1);
        for(int i=0;i<m;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }
        vector <int> sp(k);
        vector < pair <int,int> > map(n+1,make_pair(-1,-1));
        queue <int> q;
        int t = 0;
        for(int i=0;i<k;i++){
            cin>>sp[i];
            map[sp[i]] = make_pair(0,t);
            t++;
            q.push(sp[i]);
        }
        int total = k;
        while(!q.empty() && total<n){
            int x = q.front();
            q.pop();
            for(int i=0;i<v[x].size();i++){
                if(map[v[x][i]].second!=-1)
                    continue;
                map[v[x][i]].second = map[x].second;
                map[v[x][i]].first = map[x].first + 1;
                q.push(v[x][i]);
                total++;
            }
        }
        int Q;
        cin>>Q;
        while(Q-->0){
            int x;
            cin>>x;
            cout<<map[x].first<<endl;
        }
    }
}