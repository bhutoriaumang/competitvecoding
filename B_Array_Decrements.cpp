/*

Problem Tags: ['greedy', 'implementation'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> a(n),b(n);
        int d = 0;
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++){
            cin>>b[i];
            d = max(d,a[i]-b[i]);
        }
        int f = 1;
        for(int i=0;i<n;i++){
            // cout<<max(a[i]-d,0)<<endl;
            if(max(a[i]-d,0)!=b[i]){
                f = 0;
                break;
            }
        }
        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}