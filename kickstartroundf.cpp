#include </Users/bits/stdc++.h>
using namespace std;
int main(){
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        int d,n,k;
        cin>>d>>n>>k;
        vector < pair <int,int> > v,t;
        map < pair <int,int> , int > h;
        for(int i=0;i<n;i++){
            int a,b,c;
            cin>>a>>b>>c;
            pair <int,int> temp = make_pair(b,c);
            v.push_back(temp);
            h[temp] = a;
        }
        sort(v.begin(),v.end());
        int f = 0;
        long long int maximum = 0;
        for(int i=1;i<=d;i++){
            while(f<n && v[f].first<=i){
                t.push_back(make_pair(v[f].second,v[f].first));
                f++;
            }
            sort(t.rbegin(),t.rend());
            priority_queue<int, vector <int> , greater <int> > hh;
            long long int sum = 0;
            for(int j=0;j<t.size();j++){
                pair <int,int> tem = make_pair(t[j].second,t[j].first);
                if(hh.size()<k){
                    hh.push(h[tem]);
                    sum+=h[tem];
                }
                else{
                    long long temp = max(hh.top(),h[tem]);
                    sum-=hh.top();
                    hh.pop();
                    hh.push(temp);
                    sum+=temp;
                }
            }
            maximum = max(maximum,sum);
            if(t.size()>0){
                while(t.size()>0 && t.back().first==i){
                    t.pop_back();
                }
            }
        }
        cout<<"Case #"<<cas<<": "<<maximum<<endl;
    }
}