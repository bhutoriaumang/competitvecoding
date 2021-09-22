#include </Users/bits/stdc++.h>
using namespace std;

void display(stack <int> s){
    while(!s.empty()){
        cout<<s.top()<<"\t";
        s.pop();
    }
    cout<<endl;
}

bool hasCycle(vector <vector <int> > a,vector <int> vis, vector <int> visited , int t){
    stack <int> s;
    s.push(t);
    vis[t] = 1;
    visited[t] = 1;
    while(!s.empty()){
        int i = s.top();
        s.pop();
        for(int j=0;j<a[i].size();j++){
            if(vis[a[i][j]])
                return true;
            s.push(a[i][j]);
            vis[a[i][j]] = 1;
            visited[a[i][j]] = 1;
        }
    }
    vis.assign(visited.size(),0);
    for(int i=0;i<visited.size();i++){
        if(visited[i]==0)
            return hasCycle(a,vis,visited,i);
    }
    return false;
}

int main(){
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        int n;
        cin>>n;
        vector <vector <int> > a;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            vector <int> temp(k);
            for(int j=0;j<k;j++){
                cin>>temp[j];
                temp[j]--;
            }
            a.push_back(temp);
        }
        vector <int> vis(n,0);
        cout<<"Case #"<<cas<<": "<<((hasCycle(a,vis,vis,0))?"Yes":"No")<<endl;
    }
}


/*
0
1->2 1->3 2->3
2->0
1->2
2->3

2->1
2
2->3
4->3

1
5
0
1 1
2 2 4
0
1 3 
*/