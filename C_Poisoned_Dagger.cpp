/*

Problem Tags: ['binary search'] 

*/

#include <bits/stdc++.h>
using namespace std;

bool deals(vector <long long int> v, long long int x,long long int h){
    for(int i=0;i<v.size()-1;i++){
        h-= min(x,v[i+1]-v[i]);
    }
    h-=x;
    return (h<=0);
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n,h;
        cin>>n>>h;
        vector <long long int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        long long int l = 1,u=pow(10,18),m=(l+u)/2;
        while(l<u){
            m = (l+u)/2;
            if(deals(v,m,h))
                u = m;
            else
                l = m+1;
        }
        cout<<u<<endl;
    }
}