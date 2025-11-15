/*

Problem Tags: ['constructive algorithms', 'greedy'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        long long int h1,h2,h3;
        h3=0;
        h2=1;
        h1=2;
        n-=3;
        while((n-3)>=0){
            n-=3;
            h1++;
            h2++;
            h3++;
        }
        if(n==2){
            h1++;
            h2++;
        }
        else if(n==1)
            h1++;
        cout<<h2<<" "<<h1<<" "<<h3<<endl;
    }
}