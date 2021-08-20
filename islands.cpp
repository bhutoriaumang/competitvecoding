#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin>>n>>m;
    vector <pair <int,int> > v;

    for(int i=0;i<m;i++){
        int a,b;
        cin>>a>>b;
        v.push_back(make_pair(a,b));
    }
    sort(v.begin(),v.end());
    int c = 1,x=v[0].first,y=v[0].second;
    for(int i=1;i<m;i++){
        if(y<=v[i].first){
            c++;
            x = v[i].first;
            y = v[i].second;
        }
        else{
            x = v[i].first;
            y = (y>v[i].second)?v[i].second:y;
        }
    }
    cout<<c<<endl;
}