#include <bits/stdc++.h>
using namespace std;

vector <long long int> ans(3,0);
long long int mod = 998244353;
int co=0;
void calc(vector <long long int> f,long long int c,long long int n,long long int x,long long int t){
    if(f[n-1]!=0){
        co++;
        cout<<co<<endl;
        return;
        long long int flag = 0;
        if(f[n-1]==1){
            ans[0]++;
            // cout<<ans[0]<<" "<<ans[2]<<" "<<ans[1]<<endl;
            return;
        }
        if(f[n-1]==2 && f[0]==1){
            ans[2]++;
            // cout<<ans[0]<<" "<<ans[2]<<" "<<ans[1]<<endl;
            return;
        }
        // for(int i=0;i<n;i++)
        //     cout<<f[i]<<" ";
        // cout<<endl;
        for(long long int i=n-1;i>0;i--){
            if(f[i]==f[i-1] && i>2){
                if(f[i]==1){
                    ans[0]++;
                    ans[0]%=mod;
                    flag=1;
                }
                else if(f[i]==2){
                    ans[2]++;
                    ans[2]%=mod;
                    flag=1;
                }
                break;
            }
        }
        if(flag==0){
            ans[1]++;
            ans[1]%=mod;
        }
        // cout<<ans[0]<<" "<<ans[2]<<" "<<ans[1]<<endl;
        return;
    }
    if(c<(n/2)){
        if(c==0)
            t=x;
        f[x]=1;
        c++;
        calc(f,c,n,x+1,t);
        f[x]=0;
        c--;
    }
    if((x-c)<(n/2)){
        f[x]=2;
        calc(f,c,n,x+1,t);
        f[x]=0;
    }
}

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        vector <long long int> v(n),f(n,0);
        ans.clear();
        ans.push_back(0);
        ans.push_back(0);
        ans.push_back(0);
        for(long long int i=1;i<=n;i++)
            v[i-1]=i;
        calc(f,0,n,0,0);
        cout<<ans[0]<<" "<<ans[2]<<" "<<ans[1]<<endl;
    }
}

/*


Alex wins-
if he has n
if he has n-1 & n-2 & n-3


Alex loses-
if his best card <=n-2



*/