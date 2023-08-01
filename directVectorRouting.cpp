#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cout<<"Enter no of nodes : ";
    cin>>n;
    vector < vector <int> > v(n, vector <int>(n,1e6)),d(n, vector <int>(n,-1));
    cout<<"Enter the distance matrix:\n\n";
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>v[i][j];
            if(i!=j && v[i][j]==0)
                v[i][j] = 1e6;
            d[i][j] = j;
        }
    }
    int f=1;
    while(f){
        f=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==1e6 || i==j)
                    continue;
                vector <int> t(n,1e6);
                for(int k=0;k<n;k++){
                    if(k==j)
                        continue;
                    t[k] = v[i][j]+v[j][k];
                    if(t[k]<v[i][k]){
                        v[i][k] = t[k];
                        if(d[i][k]==k)
                            d[i][k] = j;
                        f = 1;
                    }
                }
            }
        }
    }
    cout<<"\nFinal Routing Tables :\n\n";
    for(int i=0;i<n;i++){
        cout<<"Routing table for node "<<(i+1)<<" :\n";
        cout<<"NODE\tCOST\tNEXT_STEP\n\n";
        for(int j=0;j<n;j++)
            cout<<(j+1)<<"\t"<<v[i][j]<<"\t"<<(d[i][j]+1)<<endl;
        cout<<endl;
    }
}