#include <bits/stdc++.h>
using namespace std;

void print(vector <int> x,vector <int> y,int n){
    cout<<endl;
    cout<<"NODE\tCOST\tNEXT_STEP\n\n";
    for(int i=0;i<n;i++)
        cout<<(i+1)<<"\t"<<x[i]<<"\t"<<(y[i]+1)<<endl;
    cout<<endl;
}

int main(){
    int n,x;
    cout<<"Enter no of nodes : ";
    cin>>n;
    vector < vector <int> > v(n,vector <int> (n,1e6));
    cout<<"Enter the network matrix :\n\n";
    vector <int> d(n,1e6),f(n,0),t(n,0);
    for(int i=0;i<n;i++){
        t[i] = i;
        for(int j=0;j<n;j++){
            cin>>v[i][j];
            if(i!=j && v[i][j]==0)
                v[i][j] = 1e6;
        }
    }
    cout<<"Enter the required node : ";
    cin>>x;
    x--;
    int c = 1;
    for(int i=0;i<n;i++){
        if(i==x){
            d[i] = 0;
            f[i] = 1;
            continue;
        }
        d[i]=v[x][i];
    }
    while(c<n){
        int ind = -1;
        for(int i=0;i<n;i++){
            if(f[i]==1)
                continue;
            if(ind==-1 || d[ind]>d[i])
                ind = i;
        }
        c++;
        for(int i=0;i<n;i++){
            if(d[i]>(d[ind]+v[ind][i])){
                d[i] = d[ind]+v[ind][i];
                if(t[i]==i)
                    t[i] = ind;
            }
        }
        f[ind]=1;
    }
    cout<<"Routing table for node "<<(x+1)<<" :\n";
    print(d,t,n);
}