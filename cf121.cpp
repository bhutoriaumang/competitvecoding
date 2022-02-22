#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <long long int> v(n),h(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=0;i<n;i++)
            cin>>h[i];
        long long int c=0;
        vector < pair<long long int,long long int> > x;
        for(int i=0;i<n;i++){
            long long int k = v[i]-h[i]+1;
            if(x.size()==0)
                x.push_back(make_pair(k,v[i]));
            else{
                if(x.back().second >= k)
                    x.back().second = v[i];
                else
                    x.push_back(make_pair(k,v[i]));
                    
            }
        }
        for(int i=0;i<x.size();i++){
            long long int k = x[i].second-x[i].first+1;
            c+= (k*(1+k))/2;
        }
        cout<<c<<endl;
    }
}