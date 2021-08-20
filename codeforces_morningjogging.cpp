#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,m;
        cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        }
        for(int j=0;j<m;j++){
            int mi = 0;
            for(int i=0;i<n;i++){
                if(a[i][j]<a[mi][j])
                    mi = i;
            }
            int t = a[mi][j];
            a[mi][j] = a[mi][j];
            a[mi][j] = t;
        } 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }
    }
}

/*
    2 1
    4 3
    3 5
*/