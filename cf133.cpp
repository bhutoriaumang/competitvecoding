#include <bits/stdc++.h>
using namespace std;

long long int calc(vector < vector <long long int> > v,vector < vector <long long int> > f,int m,long long int time,int x,int y,int visited){
    // cout<<x<<" "<<y<<" : "<<visited<<" , "<<time<<endl;
    if(y==m || y<0){
        return 1e10;
    }
    visited++;
    f[x][y]=1;
    // cout<<x<<" "<<y<<" : "<<visited<<" , "<<time<<endl;
    // if(visited==(2*m))
    //     cout<<"!!!!\n!!!\n";
    if(visited==(2*m))
        return time;
    if(x==0 && y==0){
        return min(calc(v,f,m,max(1+time,v[x+1][y]),x+1,y,visited),calc(v,f,m,max(1+time,v[x][y+1]),x,y+1,visited));
    }
    else{
        if(x==0){
            if(f[x][y-1] && f[x+1][y-1] && !f[x+1][y] && !f[x][y+1])
                return min(calc(v,f,m,max(1+time,v[x+1][y]),x+1,y,visited),calc(v,f,m,max(1+time,v[x][y+1]),x,y+1,visited));
            else if(f[x][y-1] && y<(m-1) && !f[x][y+1])
                return calc(v,f,m,max(1+time,v[x][y+1]),x,y+1,visited);
            else if(f[x][y-1] && !f[x+1][y])
                return calc(v,f,m,max(1+time,v[x+1][y]),x+1,y,visited);
            else if(f[x+1][y] && !f[x][y-1])
                return calc(v,f,m,max(1+time,v[x][y-1]),x,y-1,visited);
        }
        else{
            if(f[x-1][y]==1 && y==(m-1) && !f[x][y-1])
                return calc(v,f,m,max(1+time,v[x][y-1]),x,y-1,visited);
            else if(y>0 && f[x][y-1] && f[x-1][y-1]==0 && y<(m-1) && !f[x][y+1])
                return calc(v,f,m,max(1+time,v[x][y+1]),x,y+1,visited);
            else if(y>0 && f[x][y-1] && f[x-1][y-1]==0 && !f[x-1][y])
                return calc(v,f,m,max(1+time,v[x-1][y]),x-1,y,visited);
            else if(y>0 && f[x][y-1] && f[x-1][y-1] && !f[x-1][y] && !f[x][y+1]){
                return min(calc(v,f,m,max(1+time,v[x-1][y]),x-1,y,visited),calc(v,f,m,max(1+time,v[x][y+1]),x,y+1,visited));
            }
            else if(f[x-1][y] && !f[x][y+1])
                return calc(v,f,m,max(1+time,v[x][y+1]),x,y+1,visited);
            else if(y>0 && f[x-1][y] && y<(m-1) && f[x][y+1] && !f[x][y-1])
                return calc(v,f,m,max(1+time,v[x][y-1]),x,y-1,visited);
            else if(y==0){
                return calc(v,f,m,max(1+time,v[x][y+1]),x,y+1,visited);
            }
        }
    }
    // cout<<"HI "<<x<<" "<<y<<endl;
    return 1e10;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int m;
        cin>>m;
        vector < vector <long long int> > v(2,vector <long long int> (m)),f(2,vector <long long int> (m,0));
        for(int i=0;i<2;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
                if(i>0 || j>0)
                    v[i][j]++;
            }
        }
        cout << calc(v,f,m,0,0,0,0) << endl;
    }
}

/*

a b c d e f
g h i j k l


*/