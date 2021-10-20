#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,m;
        cin>>n>>m;
        vector <int> v(n+m-1,0);
        vector < pair<int,int> > x;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                char c;
                cin>>c;
                if(c=='1')
                    x.push_back(make_pair(i,j));
            }
        }
        for(int i=0;i<x.size()-1;i++){
            for(int j=i+1;j<x.size();j++)
                v[abs(x[i].first - x[j].first) + abs(x[i].second - x[j].second)]++;
        }
        for(int i=1;i<v.size();i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
}