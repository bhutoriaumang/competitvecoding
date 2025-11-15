/*

Problem Tags: ['constructive algorithms'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        if(v[n-1]==1){
            cout<<"NO\n";
            continue;
        }
        cout<<"YES\n";
        vector < vector <int> > x;
        vector <int> t;
        t.push_back(0);
        for(int i=n-2;i>=0;i--){
            if(v[i]==1)
                t.push_back(1);
            else{
                x.push_back(t);
                t.clear();
                t.push_back(0);
            }
        }
        if(t.size()>0)
            x.push_back(t);
        for(int i=0;i<x.size();i++){
            for(int j=0;j<x[i].size()-1;j++)
                cout<<"0 ";
            cout<<(x[i].size()-1)<<" ";
        }
        cout<<endl;
    }
}

/*

1 0 1 0

0
1 0
0 1 0
1 0 1 0

1 0 0 1 1 0


0 0 0 1 0

0 0

1 1 0

0 0 1 0

0 0 0 1 0

0 0 0 1 0

0 0 0 1 0

1 0 1 1 1 0

1 1 0 0 0

1 0 0 1 1 0

*/