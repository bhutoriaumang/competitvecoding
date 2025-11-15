/*

Problem Tags: ['implementation', 'math'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        long long int k;
        cin>>k;
        long long int r = (ceil(sqrt(k))),c=1;
        long long int a = r*r;
        while(a!=k){
            a--;
            // cout<<a<<"\t"<<r<<"\t"<<c<<"\t"<<k<<endl;
            if(a==(r*(r-1))){
                r--;
                break;
            }
            c++;
        }
        while(a!=k){
            // cout<<a<<"\t"<<r<<"\t"<<c<<"\t"<<k<<endl;
            a--;
            r--;
        }
        cout<<r<<" "<<c<<endl;
    }
}