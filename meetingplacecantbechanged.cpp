#include <bits/stdc++.h>
using namespace std;

bool possible(vector < pair<long double,long double> > v,long double k){
    long double l = v[0].first - k*v[0].second;
    long double r = v[0].first + k*v[0].second;
    for(int i=0;i<v.size();i++){
        l = max(l,v[i].first - k*v[i].second);
        r = min(r,v[i].first + k*v[i].second);
    }
    if(l<=r)
        return true;
    else
        return false;
}

int main(){
    int n;
    cin>>n;
    vector <long double> x(n),s(n);
    for(auto &i : x)
        cin>>i;
    for(auto &i : s)
        cin>>i;
    vector < pair <long double,long double> > v;
    for(int i=0;i<n;i++)
        v.push_back(make_pair(x[i],s[i]));
    long double l=0,u=1000000000;
    while(abs(l-u)>0.000001){
        long double m = (l+u)/2;
        // cout<<l<<"\t"<<m<<"\t"<<u<<endl;
        if(possible(v,m))
            u = m;
        else
            l = m;
    }
    cout<<fixed<<setprecision(12)<<l<<endl;
}