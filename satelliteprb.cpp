#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int r,c,n;
        cin>>r>>c>>n;
        vector < pair <int,int> > v(n);
        for(int i=0;i<n;i++)
            cin>>v[i].first>>v[i].second;
        map < vector <double> , int > m;
        sort(v.begin(),v.end());
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                vector <double> t(4,0);
                double a = (double)(v[j].second-v[i].second);
                double b = (double)(v[i].first-v[j].first);
                t[0] = -a/b;
                if(b==0)
                    t[0] = abs(t[0]);
                if(a!=0)
                    t[1] = (a*v[i].first + b*v[i].second)/a;
                else
                    t[1] = v[i].second;
                t[3] = sqrt(a*a + b*b);
                if(m.find(t)==m.end())
                    m[t] = 1;
                else
                    m[t]++;
            }
        }
        int ans = 0;
        for (auto& it : m){
            ans = max(ans,it.second);
        }
        cout<<ans+1<<endl;
    }
}

/*

* * * * *
x * * * *
x * * * x
* * x * *
* x * x *

*/