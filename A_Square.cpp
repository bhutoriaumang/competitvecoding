#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        vector < pair <long long int,long long int> > v(4);
        for(int i=0;i<4;i++)
            cin>>v[i].first>>v[i].second;
        long long int s;
        if(v[0].first==v[1].first)
            s = abs(v[0].second-v[1].second);
        else if(v[0].first==v[2].first)
            s = abs(v[0].second-v[2].second);
        else
            s = abs(v[0].second-v[3].second);
        cout<<s*s<<endl;
    }
}