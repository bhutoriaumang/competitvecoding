/*

Problem Tags: ['greedy', 'implementation', 'sortings'] 

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
        sort(v.begin(),v.end());
        long long int c = (n/2);
        int i = 1;
        while(c-->0){
            cout<<v[i++]<<" "<<v[0]<<endl;
        }
    }
}