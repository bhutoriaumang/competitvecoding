#include </Users/bits/stdc++.h>
using namespace std;
# define lli long long int

int main(){
    int n;
    cin>>n;
    vector < pair <long long int,long long int> > v,x;
    vector <int> t(n+1,0);
    vector <long long int> et;
    for(int i=0;i<n;i++){
        long long int x,y;
        cin>>x>>y;
        v.push_back(make_pair(x,x+y-1));
        et.push_back(x);
        et.push_back(x+y-1);
    }
    sort(v.begin(),v.end());
    sort(et.begin(),et.end());
    priority_queue < pair<lli,lli> , vector < pair <lli,lli> > , greater < pair<lli,lli> > > pq;
    int k=0;
    for(int i=1;i<et.size();i++){
        if(et[i]==et[i-1])
            continue;
        while(k<n && v[k].first<=et[i]){
            pq.push(make_pair(v[k].second,v[k].first));
            k++;
        }
        t[pq.size()]+=et[i]-et[i-1];
        for(int i=1;i<=n;i++){
            cout<<t[i]<<" ";
        }
        cout<<endl;
        while(pq.size()>0 && pq.top().first==et[i])
            pq.pop();
    }
    t[pq.size()]++;
    for(int i=1;i<=n;i++){
        cout<<t[i]<<" ";
    }
    cout<<endl;
}

/*

1:  1
2:  1,2
3:  2,3
4:  2

10^6 : 1,2
20^6 : 1,2
20^6+1 : null

*/