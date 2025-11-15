/*

Problem Tags: ['brute force', 'dp'] 

*/

#include <iostream>
using namespace std;

int main(){
    int n,a,b,c;
    cin>>n>>a>>b>>c;
    if(a<c){
        int t = a;
        a = c;
        c = t;
    }
    if(a<b){
        int t = a;
        a = b;
        b = t;
    }
    if(b<c){
        int t = b;
        b = c;
        c = t;
    }
    int dp[max(a,n)+1];
    for(int i=0;i<=n;i++)
        dp[i] = 0;
    dp[c] = 1;
    dp[a] = 1;
    dp[b] = 1;
    for(int i=c+1;i<=n;i++){
        int ax,bx,cx;
        if(i-a>=0)
        {
            ax = dp[i-a];
        }
        else
        {
            ax = 0;
        }
        if(i-b>=0)
        {
            bx = dp[i-b];
        }
        else
        {
            bx = 0;
        }
        if(i-c>=0)
        {
            cx = dp[i-c];
        }
        else
        {
            cx = 0;
        }
        if(max(max(dp[i],ax),max(bx,cx))!=0)
            dp[i] = max(max(0,ax),max(bx,cx)) + 1;
    }
    cout<<dp[n]<<endl;
}