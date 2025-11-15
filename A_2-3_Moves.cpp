/*

Problem Tags: ['greedy', 'math'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        long long int ans = 0;
        if(n%3==0)
            ans = n/3;
        else if((n-2)%3==0)
            ans = (n-2)/3 + 1;
        else if((n-4)%3==0)
            ans = max((n-4)/3,(long long int)0) + 2;
        else
            ans = 2;
        cout<<ans<<endl;
    }
}

// 5 = 3x+2y