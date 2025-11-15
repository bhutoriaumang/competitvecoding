/*

Problem Tags: ['bitmasks', 'greedy', 'math'] 

*/

#include <bits/stdc++.h>
using namespace std;

vector <int> convert(vector <int> x,long long int d){
    int p = x.size()-1;
    while(d>0){
        x[p--]+=d%2;
        d/=2;
    }
    return x;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,l;
        cin>>n>>l;
        vector <long long int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        vector <int> x(l);
        for(int i=0;i<n;i++)
            x = convert(x,v[i]);
        vector <int> s(l);
        for(int i=0;i<l;i++)
            s[i] = (x[i]>(n-x[i]))?1:0;
        long long int ans = 0,p=0;
        for(int i=l-1;i>=0;i--){
            ans += (s[i]*pow(2,p));
            p++;
        }
        cout<<ans<<endl;
    }
}