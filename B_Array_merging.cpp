/*

Problem Tags: ['constructive algorithms', 'greedy'] 

*/

#include <bits/stdc++.h>
using namespace std;

vector <int> cal(vector <int> v,int n){
    vector <int> x(2*n + 1,0);
    for(int i=0;i<n;i++){
        int c = 1;
        while(i<n-1 && v[i]==v[i+1]){
            c++;
            i++;
        }
        x[v[i]] = max(x[v[i]],c);
    }
    return x;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> a(n),b(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        vector <int> aa = cal(a,n);
        vector <int> bb = cal(b,n);
        int ans = 0;
        for(int i=0;i<aa.size();i++)
            ans = max(ans,aa[i]+bb[i]);
        cout<<ans<<endl;
    }
}