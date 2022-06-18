#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        vector <long long int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        vector < vector <long long int> > x;
        vector <long long int> a;
        a.push_back(v[0]);
        for(int i=1;i<n;i++){
            if(v[i-1]>=v[i]){
                x.push_back(a);
                a.clear();
                a.push_back(v[i]);
            }
            else
                a.push_back(v[i]);
        }
        x.push_back(a);
        long long int m = 0;
        for(int i=1;i<x.size();i++){
            m = max(m,(long long int)x[i].size()+(long long int)x[i-1].size());
            if(i<(x.size()-1)){
                if((x[i][x[i].size()-1]+(x[i-1][x[i-1].size()-1]-x[i][0]+1))<x[i+1][0])
                    m = max(m,(long long int)x[i].size()+(long long int)x[i-1].size()+(long long int)x[i+1].size());
            }
        }
        cout<<m<<endl;
    }
}