#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,m,r1,r2;
        cin>>n>>m>>r1>>r2;
        int a[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        }
        vector < vector < pair <int,int> > > a1(200),a2(200);
        int b1[n][m],b2[n][m];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(a[i][j]==0){
                    int x = i+j;
                    int y = i+(m-1-j);
                    a1[(int)ceil((double)x/(double)r1)].push_back(make_pair(i,j));
                    a2[(int)ceil((double)y/(double)r2)].push_back(make_pair(i,j));
                    b1[i][j] = ceil((double)x/(double)r1);
                    b2[i][j] = ceil((double)y/(double)r2);
                }
                else{
                    b1[i][j] = -1;
                    b2[i][j] = -1;
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cout<<b1[i][j]<<"\t";
            cout<<endl;
        }
        cout<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++)
                cout<<b2[i][j]<<"\t";
            cout<<endl;
        }
        cout<<endl;
    }
}