#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int d,n,k;
        cin>>d>>n>>k;
        vector < pair<int,int> > v;
        map < pair<int,int> , int > m;
        for(int i=0;i<n;i++){
            int x,y,z;
            cin>>x>>y>>z;
            v.push_back(make_pair(y,z));
            m[make_pair(y,z)] = x;
        }
        sort(v.begin(),v.end());
        priority_queue < pair <int,int> , vector < pair<int,int> > , greater < pair<int,int> > > pq;
        
    }
}