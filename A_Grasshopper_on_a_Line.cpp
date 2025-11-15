/*

Problem Tags: ['constructive algorithms', 'math'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int x,k;
        cin>>x>>k;
        if(x%k==0)
            cout<<"2\n"<<(x-1)<<" 1"<<endl;
        else
            cout<<"1\n"<<x<<endl;
    }
}