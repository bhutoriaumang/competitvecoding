/*

Problem Tags: ['greedy'] 

*/

#include <bits/stdc++.h>
using namespace std;

void display(vector <long long int> v ){
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <long long int> v(n),f(n,0);
        for(int i=0;i<n;i++)
            cin>>v[i];
        v.push_back(1000000000);
        int ans = 0;
        for(int i=1;i<n-1;i++){
            if(v[i]>v[i-1] && v[i]>v[i+1]){
                // cout<<"HI\n";
                // if(v[i+1]<v[i+2]){
                //     v[i+1] = max(v[i],v[i+2]);
                //     if(f[i+1]==0)
                //         ans++;
                //     f[i+1] = 1;
                // }
                // else if(i!=0 && v[i-1]<v[i-2]){
                //     v[i-1] = max(v[i],v[i-2]);
                //     if(f[i-1]==0)
                //         ans++;
                //     f[i-1] = 1;
                // }
                // else{
                //     v[i] = max(v[i-1],v[i+1]);
                //     if(f[i]==0)
                //         ans++;
                //     f[i] = 1;
                // }
                v[i+1] = max(v[i+2],v[i]);
                ans++;
            }
            // display(v);
        }
        cout<<ans<<endl;
        for(int i=0;i<n;i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
}