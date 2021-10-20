#include </Users/bits/stdc++.h>
using namespace std;

bool check(vector <vector <int> > v, int i, int j){
    int n = v.size();
    for(int k=1;k<n;k++){
        if((i+k)<n && (j+k)<n){
            if(v[i+k][j+k]==1)
                return false;
        }
        if((i+k)<n && (j-k)>=0){
            if(v[i+k][j-k]==1)
                return false;
        }
        if((i-k)>=0 && (j+k)<n){
            if(v[i-k][j+k]==1)
                return false;
        }
        if((i-k)>=0 && (j-k)>=0){
            if(v[i-k][j-k]==1)
                return false;
        }
    }
    return true;
}

pair <vector <vector <int> > , int> construct(vector <vector <int> > v,int n, vector <int> f,int k){
    if(k==n)
        return make_pair(v,1);
    int flag = 0;
    for(int i=0;i<n;i++){
        if(f[i]==1)
            continue;
        v[k][i] = 1;
        f[i] = 1;
        if(!check(v,k,i)){
            v[k][i] = 0;
            f[i] = 0;
            continue;
        }
        pair <vector <vector <int> > , int> t = construct(v,n,f,k+1);
        if(t.second==1){
            flag = 1;
            v = t.first;
            break;
        }
        v[k][i] = 0;
        f[i] = 0;
    }
    return make_pair(v,flag);
}

int main(){
    int n;
    cin>>n;
    vector < vector <int> > v;
    vector <int> f(n,0);
    for(int i=0;i<n;i++){
        v.push_back(f);
    }
    v = construct(v,n,f,0).first;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<v[i][j]<<" ";
        cout<<endl;
    }
}