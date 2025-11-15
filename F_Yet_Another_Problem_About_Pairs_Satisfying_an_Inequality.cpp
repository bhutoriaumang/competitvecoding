/*

Problem Tags: ['binary search', 'data structures', 'dp', 'greedy', 'sortings'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        vector <long long int> v(n),x(n);
        long long int c = 0;
        for(long long int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]<=i){
                c++;
            }
            x[i] = c;
        }
        long long int ans = 0;
        for(long long int i=2;i<n;i++){
            if(v[i]<=i && v[i]>1){
                ans += x[v[i]-2];
            }
        }
        cout<<ans<<endl;
    }
}