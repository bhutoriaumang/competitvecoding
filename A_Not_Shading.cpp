#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,m,r,c;
        cin>>n>>m>>r>>c;
        vector < vector <int> > v(n+1,vector<int>(m+1,-1));
        int count=0;
        for(int i=1;i<=n;i++){
            string s;
            cin>>s;
            for(int j=1;j<=m;j++){
                v[i][j] = (s[j-1]=='B')?1:0;
                if(s[j-1]=='B')
                    count++;
            }
        }
        if(count==0)
            cout<<"-1\n";
        else if(v[r][c]==1)
            cout<<"0\n";
        else{
            int f = 0;
            for(int i=1;i<=n;i++){
                if(v[i][c]==1){
                    f = 1;
                    break;
                }
            }
            for(int i=1;i<=m;i++){
                if(v[r][i]==1){
                    f = 1;
                    break;
                }
            }
            if(f==1)
                cout<<"1\n";
            else
                cout<<"2\n";
        }
    }
}