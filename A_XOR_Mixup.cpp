/*

Problem Tags: ['bitmasks', 'brute force'] 

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
        long long int x = 0;
        for(int i=0;i<n;i++)
            x = x^v[i];
        long long int f = -1;
        for(int i=0;i<n;i++){
            if((v[i]^x) == v[i]){
                f = v[i];
                break;
            }
        }
        cout<<f<<endl;
    }
}