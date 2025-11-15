/*

Problem Tags: ['constructive algorithms'] 

*/

#include <bits/stdc++.h>
using namespace std;

void display(int x){
    for(int i=0;i<x;i++)
        cout<<"(";
    for(int i=0;i<x;i++)
        cout<<")";
}

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            display(i);
            display(n-i);
            cout<<endl;
        }
    }
}