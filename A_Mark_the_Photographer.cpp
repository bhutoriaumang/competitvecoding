/*

Problem Tags: ['greedy', 'sortings'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,x;
        cin>>n>>x;
        vector <int> v(2*n);
        for(int i=0;i<2*n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        int f = 1;
        for(int i=0;i<n;i++){
            if((v[i+n]-v[i])<x){
                f=0;
                break;
            }
        }
        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}