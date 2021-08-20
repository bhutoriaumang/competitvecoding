#include </Users/bits/stdc++.h>
using namespace std;

void bruteforce(int n,int m,int p, vector<vector<int> > a,vector<vector<int> > b){
    int c[n][p];
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            c[i][j] = 0;
            for(int k=0;k<m;k++){
                c[i][j]+= a[i][k]*b[k][j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<a[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<m;i++){
        for(int j=0;j<p;j++)
            cout<<b[i][j]<<"\t";
        cout<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++)
            cout<<c[i][j]<<"\t";
        cout<<endl;
    }
}

int main(){
    int n,m,p;
    cin>>n>>m>>p;
    vector <vector<int> > a,b;
    for(int i=0;i<n;i++){
        vector <int> t(m);
        for(auto &j : t)
            cin>>j;
        a.push_back(t);
    }
    for(int i=0;i<m;i++){
        vector <int> t(p);
        for(auto &j : t)
            cin>>j;
        b.push_back(t);
    }
    bruteforce(n,m,p,a,b);
}