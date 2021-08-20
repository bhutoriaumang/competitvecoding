#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;

#define max 5

long long int minimum(long long int v[],long long int d[]){
    long long int mini = 10000;
    long long int minindex = -1;
    for(long long int i=0;i<max;i++){
        if(v[i]==0){
            if(d[i]<mini){
                mini = d[i];
                minindex = i;
            }
        }
    }
    
    return minindex;
}

int main(){
    double a[max][max];
    for(long long int i=0;i<max;i++){
        for(long long int j=0;j<max;j++){
            a[i][j] = 10000;
        }
    }

    a[0][1] = 10;
    a[0][2] = 3;
    a[1][2] = 1;
    a[1][3] = 2;
    a[2][1] = 4;
    a[2][3] = 8;
    a[2][4] = 2;
    a[3][4] = 7;
    a[4][3] = 9;

    long long int dist[max],visited[max],lastvertex[max];
    for(long long int i=0;i<max;i++){
        dist[i] = 10000;
        visited[i] = 0;
    }
    dist[0] = 0;
    lastvertex[0] = 0;

    for(long long int i=0;i<max;i++){
        long long int j = minimum(visited,dist);
        visited[j] = 1;

        for(long long int k=0;k<max;k++){
            if(visited[k]==0 && dist[k]>(dist[j]+a[j][k])){
                dist[k] = dist[j]+a[j][k];
                lastvertex[k] = j;    
            }
        }
    }

    for(int i=0;i<max;i++){
        cout<<lastvertex[i]<<" ";
    }
    cout<<endl;

    for(long long int i=0;i<max;i++){
        cout<<"Distance from vertex 0 to vertex "<<i<<" is : ";
        cout<<dist[i]<<endl;
        cout<<"The path from vertex 0 to vertex "<<i<<" is : ";
        int t = i;
        vector <char>v;
        while(t!=0){
            t = lastvertex[t];
            v.push_back((char)(65+t));
        }
        for(int i=v.size()-1;i>=0;i--)
            cout<<v[i]<<" -> ";
        cout<<(char)(65+i)<<endl;
    }

}