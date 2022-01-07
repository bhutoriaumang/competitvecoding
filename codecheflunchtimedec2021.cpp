#include </Users/bits/stdc++.h>
using namespace std;

pair <int,int> posminmax(vector < vector <long long int> > v,int n,int x,int y){
    int a,b;
    for(int i=x;i<=y;i++){
        if(v[i][2]==x)
            a = v[i][0];
        if(v[i][2]==y)
            b = v[i][0];
    }
    return make_pair(a,b);
}

int cal(vector < vector <long long int> > v,int n,int x,int y){
    while(x<n && v[x][0]==v[x][2])
        x++;
    while(y>=0 && v[y][0]==v[y][2])
        y--;
    pair <int,int> minmax = posminmax(v,n,x,y);
    if(minmax.first>minmax.second)
        return (v[minmax.second][1]-v[minmax.first][1]);
    int a = posminmax(v,n,x,minmax.first).second;
    for(int i=minmax.first;i<=a;i++){
        if(v[i][2]>v[a][2])
            a = i;
        if(i==a)
            
    }
    int b = posminmax(v,n,minmax.second,y).first;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <long long int> v(n);
        vector < vector <long long int>  > x;
        for(int i=0;i<n;i++){
            cin>>v[i];
            vector <long long int> t;
            t.push_back(0);
            t.push_back(v[i]);
            t.push_back(i);
            x.push_back(t);
        }
        sort(x.begin(),x.end());
        for(int i=0;i<n;i++){
            x[i][0] = x[i][2];
            x[i][2] = i;
        }
        sort(x.begin(),x.end());

    }
}