#include <bits/stdc++.h>
using namespace std;

bool check(vector < pair <long long int,long long int> > v,double t){
    double l=v[0].first - t*v[0].second,r=v[0].first + t*v[0].second;
    int n = v.size();
    for(int i=1;i<n;i++){
        l = max(l,v[i].first - t*v[i].second);
        r = min(r,v[i].first + t*v[i].second);
    }
    return (l<=r);
}

int main(){
    int n;
    cin>>n;
    vector < pair<long long int,long long int> > v(n);
    double l,u,m;
    for(int i=0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    sort(v.begin(),v.end());
    l = 0;
    u = 1e9;
    while((u-l)>1e-6){
        m = (l+u)/2;
        if(check(v,m))
            u = m;
        else
            l = m;
    }
    cout<<fixed<<setprecision(20)<<l<<endl;
}