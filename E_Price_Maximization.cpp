/*

Problem Tags: ['binary search', 'greedy', 'math', 'two pointers'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        long long int n,k;
        cin>>n>>k;
        vector <long long int> v(n);
        for(long long int i=0;i<n;i++)
            cin>>v[i];
        long long int ans = 0;
        vector <long long int> x(n);
        for(long long int i=0;i<n;i++){
            long long int a = v[i]/k;
            double b = v[i]%k;
            x[i] = b;
            ans+=a;
        }
        sort(x.begin(),x.end(),greater<double>());
        for(long long int i=0;i<n;i++){
            if((n-1)<=i)
                break;
            long long int a = x[i];
            long long int b = x[n-1];
            while((n-1)>i && (a+b)<k){
                n--;
                if((n-1)>i){
                    b = x[n-1];
                }
            }
            if((a+b)>=k){
                ans++;
                n--;
            }
        }
        cout<<ans<<endl;
    }
}