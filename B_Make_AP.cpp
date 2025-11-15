/*

Problem Tags: ['implementation', 'math'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int a,b,c,d1,d2,d3;
        cin>>a>>b>>c;
        d1 = b-a;
        d2 = c-b;
        d3 = c-a;
        long long int x = b+d1;
        if(x%c==0 && (x/c)>0){
            cout<<"YES\n";
            continue;
        }
        x = b-d2;
        if(x%a==0 && (x/a)>0){
            cout<<"YES\n";
            continue;
        }
        if(d3%2==0){
            x = a+(d3/2);
            if(x%b==0 && (x/b)>0){
                cout<<"YES\n";
                continue;
            }
        }
        cout<<"NO\n";
    }
}