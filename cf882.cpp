#include <bits/stdc++.h>
using namespace std;

int cal(int x,map <int,int> m){
    cout<<x<<" : ";
    for(int i=256;i>x;i--){
        int s = x^i;
        if(m.find(s)!=m.end() && m[s]!=0){
            cout<<s<<","<<i<<" ";
            m[s]--;
            cout<<endl;
            return cal(i,m);
        }
    }
    cout<<endl;
    return x;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n);
        map <int,int> m;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(m.find(v[i])==m.end())
                m[v[i]]=1;
            else
                m[v[i]]++;
        }
        int ans = v[0];
        for(int i=0;i<n;i++){
            m[v[i]]--;
            ans = max(ans,cal(v[i],m));
            m[v[i]]++;
        }
        cout<<ans<<endl;
    }
}