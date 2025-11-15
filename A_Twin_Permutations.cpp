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
        for(int i=0;i<n;i++){
            cin>>v[i];
            cout << (n+1 - v[i]) << " ";
        }
        cout<<endl;
    }
}