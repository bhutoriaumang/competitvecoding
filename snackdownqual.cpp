#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector < pair<int,int> > xx,x(n),y;
        for(int i=0;i<n;i++){
            cin>>x[i].first;
            x[i].second = i;
            xx.push_back(x[i]);
        }
        sort(x.begin(),x.end());
        int s = 0,i=0;
        while(i<n){
            while(i<(n-1) && x[i].first==x[i+1].first){
                i++;
            }
            int j = y.size();
            int f = 0;
            while(j<=i){
                if(s<x[i].first){
                    y.push_back(make_pair(x[i].second,s));
                    s++;
                }
                else{
                    f = 1;
                    y.push_back(make_pair(x[i].second,s));
                }
                j++;
            }
            i++;
        }
        if(n>1 && x[n-1].first!=x[n-2].first){
            y.push_back(make_pair(n-1,x[n-1].first-1));
        }
        sort(y.begin(),y.end());
        for(int i=0;i<n;i++){
            cout<<y[i].second<<" ";
        }
        cout<<endl;
    }
}