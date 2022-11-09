#include <bits/stdc++.h>
using namespace std;

long long int ans = 0,xx=1;
void calc(vector < vector <long long int> > m, vector < vector <long long int> > v,long long int n,long long int e,long long int t,long long int x,vector <long long int> f,long long int p){
    t+=v[x][2];
    ans = max(ans,t);
    // cout<<ans<<" "<<t<<" "<<xx<<" : "<<x<<endl;
    f[x]=1;
    for(long long int i=0;i<n;i++){
        if(i==x)
            continue;
        if(m[x][i]==2)
            continue;
        if(f[i])
            continue;
        long long int fl = (p!=m[x][i] && m[x][i]!=0)?e:0;
        f[i]=1;
        calc(m,v,n,e,t-fl,i,f,m[x][i]);
        f[i]=0;
    }
}

int main(){
    long long int T;
    cin>>T;
    for(long long int cas=1;cas<=T;cas++){
        cout<<"Case #"<<cas<<": ";
        long long int n,e;
        ans=0;
        cin>>n>>e;
        vector < vector <long long int> > v(n,vector <long long int>(3));
        for(long long int i=0;i<n;i++)
            cin>>v[i][0]>>v[i][1]>>v[i][2];
        sort(v.begin(),v.end());
        vector < vector <long long int> > m(n,vector <long long int> (n,2));
        for(long long int i=0;i<n;i++){
            for(long long int j=0;j<n;j++){
                if(i==j)
                    continue;
                if(v[i][1]>v[j][1]){
                    long long int t = v[j][0]-v[i][0];
                    m[i][j] = ((t!=0)?(t/abs(t)):0);
                }
                else if(v[i][1]<v[j][1]){
                    long long int t = v[i][0]-v[j][0];
                    m[j][i] = ((t!=0)?(t/abs(t)):0);
                }
                else{
                    long long int t = v[i][0]-v[j][0];
                    m[j][i] = ((t!=0)?(t/abs(t)):0);
                    m[i][j] = -m[j][i];
                }
            }
        }
        // for(long long int i=0;i<n;i++){
        //     for(long long int j=0;j<n;j++)
        //         cout<<m[i][j]<<"\t";
        //     cout<<endl;
        // }
        vector <long long int> f(n,0);
        for(long long int i=0;i<n;i++){
            calc(m,v,n,e,0,i,f,1);
            xx++;
        }
        cout<<ans<<endl;
    }
}
/*

2 4
1 3


*/