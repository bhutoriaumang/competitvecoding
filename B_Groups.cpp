#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector < vector <int> > v(n,vector <int> (5,0)),a(5,vector <int> (5,0)),b(5,vector <int> (5,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++)
                cin>>v[i][j];
        }
        if(n%2){
            cout<<"NO\n";
            continue;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<5;j++){
                for(int k=j;k<5;k++){
                    if(j==k)
                        continue;
                    if(v[i][j] && v[i][k]){
                        a[j][k]++;
                        a[k][j]++;
                    }
                    else if(v[i][j] && !v[i][k]){
                        b[j][k]++;
                    }
                    else if(!v[i][j] && v[i][k]){
                        b[k][j]++;
                    }
                }
            }
        }
        int f = 0;
        for(int i=0;i<5;i++){
            for(int j=i;j<5;j++){
                if(i==j)
                    continue;
                int x = b[i][j];
                int y = b[j][i];
                int z = a[i][j];
                if((x+y+z)==n){
                    int t1 = (n/2) - min(n/2,x);
                    int t2 = (n/2) - min(n/2,y);
                    if((t1+t2)==z){
                        f = 1;
                        break;
                    }
                }
            }
            if(f)
                break;
        }
        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}