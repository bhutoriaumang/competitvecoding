/*

Problem Tags: ['binary search', 'greedy'] 

*/

#include <bits/stdc++.h>
using namespace std;

bool check(vector <int> v , int x){
    vector <int> a = v;
    int n = v.size();
    for(int i=n-1;i>1;i--){
        if(a[i]<x)
            return false;
        int d = min(v[i],a[i]-x)/3;
        a[i-1]+=d;
        a[i-2]+=2*d;
    }
    return ((a[0]>=x)&&(a[1]>=x));
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        int l=0,u=*max_element(v.begin(),v.end()),m=l + (u-l+1)/2;
        while(l<u){
            m = l + (u-l+1)/2;
            if(check(v,m))
                l = m;
            else
                u = m-1;
        }
        cout<<l<<endl;
    }
}