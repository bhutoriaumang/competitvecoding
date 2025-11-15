/*

Problem Tags: ['greedy'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v;
        for(int i=9;i>0;i--){
            if(i<=n){
                v.push_back(i);
                n-=i;
            }
            else{
                v.push_back(n);
                n-=n;
            }
            if(n==0)
                break;
        }
        for(int i=v.size()-1;i>=0;i--)
            cout<<v[i];
        cout<<endl;
    }
}