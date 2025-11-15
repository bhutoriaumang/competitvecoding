/*

Problem Tags: ['constructive algorithms', 'flows', 'graph matchings', 'greedy', 'math'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <long long int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        vector <int> x(n+1,0);
        sort(v.begin(),v.end(),greater<long long int>());
        bool ans = true;
        for(int i=0;i<n;i++){
            long long int t = v[i];
            while(t>n || x[t]==1)
                t/=2;
            if(t>0)
                x[t]=1;
            else{
                ans = false;
                break;
            }
        }
        cout<<((ans)?"YES\n":"NO\n");
    }
}