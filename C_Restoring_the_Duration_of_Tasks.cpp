/*

Problem Tags: ['data structures', 'greedy', 'implementation'] 

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
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        vector <int> c(n);
        c[0] = b[0]-a[0];
        for(int i=1;i<n;i++){
            c[i] = b[i] - max(a[i],b[i-1]);
        }
        for(int i=0;i<n;i++)
            cout<<c[i]<<" ";
        cout<<endl;
    }
}