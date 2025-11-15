/*

Problem Tags: ['constructive algorithms', 'greedy', 'implementation'] 

*/

#include <bits/stdc++.h>
using namespace std;

void display(vector <long long int> v){
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
        vector <long long int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        int k=0;
        while(k<n && v[k]==0){
            k++;
        }
        if(k>=(n-1)){
            cout<<"0\n";
            continue;
        }
        long long int ans = 0;
        for(int i=k;i<n-1;i++){
            if(v[i]==0){
                ans++;
            }
        }
        for(int i=0;i<n-1;i++){
            ans += v[i];
        }
        cout<<ans<<endl;
    }
}