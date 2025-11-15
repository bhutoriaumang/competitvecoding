#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n);
        vector < pair <int,int> > x(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            x[i].first = v[i];
            x[i].second = i;
        }
        sort(x.begin(),x.end());
        int t = n;
        for(int i=0;i<n;i++){
            v[x[i].second] = t--;
        }
        for(int i=0;i<n;i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
}