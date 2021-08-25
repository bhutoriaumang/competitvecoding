#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector < pair<long long int,long long int> > v;
        vector <long long int> x;
        for(int i=0;i<n;i++){
            long long int a,b;
            cin>>a>>b;
            if(x.size()==0 || find(x.begin(),x.end(),a)==x.end())
                x.push_back(a);
            v.push_back(make_pair(a,b));
        }
        sort(v.begin(),v.end());
        long long int k=1,s=v[0].second;
        for(int i=1;i<n;i++){
            if(v[i].first!=v[i-1].first){
                k++;
                s+= (k*v[i].second);
            }
            else
                s+= ((x.size())*v[i].second);
        }
        cout<<s<<endl;
    }
}