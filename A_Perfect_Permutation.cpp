/*

Problem Tags: ['constructive algorithms'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n);
        for(int i=0;i<n;i++)
            v[i] = i+1;
        for(int i=0;i<n-1;i+=2){
            swap(v[i],v[i+1]);
        }
        if((n%2)==1){
            swap(v[0],v[n-1]);
        }
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}