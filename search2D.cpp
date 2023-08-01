#include <bits/stdc++.h>
using namespace std;

int search(vector <int> v,int i,int j,int x){
    if(i==j)
        return i;
    int m = i + ((j-i)/2);
    if(v[m]>x)
        return search(v,i,m-1,x);
    else if(v[m]<x)
        return (m!=i)?(search(v,m,j,x)):((v[j]<=x)?j:i);
    else
        return m;
}

int main(){
    int n,m,t;
    cin>>n>>m;
    vector < vector <int> > v(n, vector <int>(m));
    vector <int> x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cin>>v[i][j];
        x.push_back(v[i][0]);
    }
    cin>>t;
    int i = search(x,0,n-1,t);
    int j = search(v[i],0,m-1,t);
    if(v[i][j]==t)
        cout<<"true\n";
    else
        cout<<"false\n";
}