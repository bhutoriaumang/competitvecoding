/*

Problem Tags: ['dp'] 

*/

#include <iostream>
using namespace std;

int main(){
    long long n;
    long long size = 100001;
    cin>>n;
    long long a[n];
    for(long long i=0;i<n;i++)
        cin>>a[i];
    long long dp[size];
    for(long long i=0;i<size;i++)
        dp[i] = 0;
    for(long long i=0;i<n;i++)
        dp[a[i]]++;
    long long dpp[n];
    long long k = 0;
    for(long long i=0;i<size;i++){
        if(dp[i]==0)
            continue;
        dpp[k++] = i;
        dp[i] = dp[i]*i;
    }

    long long maximum[2] = {dpp[0],(dp[dpp[0]]>dp[dpp[1]])?dpp[0]:dpp[1]};
    
    for(long long i=0;i<=dpp[k-1];i++){
        if(i==0 || i==1)
            continue;
        if(maximum[1]<i-1)
            dp[i] = max(max(dp[i-1],dp[i-2]+dp[i]),dp[i]+dp[maximum[1]]);
        else if(maximum[0]<i-1)
            dp[i] = max(max(dp[i-1],dp[i-2]+dp[i]),dp[i]+dp[maximum[0]]);
        else
            dp[i] = max(max(dp[i-1],dp[i-2]+dp[i]),dp[i]);
        if(dp[i]>dp[maximum[1]]){
            maximum[0] = maximum[1];
            maximum[1] = i;
        }
        else if(dp[i]>maximum[0]){
            maximum[0] = i;
        }
    }

    cout<<dp[dpp[k-1]]<<endl;
}