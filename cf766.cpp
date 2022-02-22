#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <vector <int> > v(n+1);
        vector <vector <int> > order(n-1,vector <int>(3,-1));
        int k=0;
        for(int i=0;i<n-1;i++){
            int x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
            if(x>y)
                swap(x,y);
            order[k][0] = x;
            order[k][1] = y;
            order[k++][2] = i;
        }
        int f = 0;
        int x = -1;
        for(int i=1;i<v.size();i++){
            if(v[i].size()>2){
                f = 1;
                break;
            }
            if(v[i].size()==1){
                x = i;
            }
        }
        if(f==1){
            cout<<"-1\n";
            continue;
        }
        if(x==-1)
            x = 1;
        vector < vector <int> > ans(n-1,vector <int>(3,-1));
        k = 0;
        int d = 2;
        while(v[x].size()!=0){
            int y = v[x][0];
            ans[k][0] = min(x,y);
            ans[k][1] = max(x,y);
            ans[k++][2] = d;
            if(d==2)
                d=3;
            else
                d=2;
            if(v[y].size()==2 && v[y][1]==x)
                v[y].erase(v[y].begin()+1,v[y].end());
            else
                v[y].erase(v[y].begin(),v[y].begin()+1);
            x = y;
        }
        vector <pair<int,int> > answer;
        sort(order.begin(),order.end());
        sort(ans.begin(),ans.end());
        for(int i=0;i<ans.size();i++)
            answer.push_back(make_pair(order[i][2],ans[i][2]));
        sort(answer.begin(),answer.end());
        for(int i=0;i<answer.size();i++)
            cout<<answer[i].second<<" ";
        cout<<endl;
    }
}