/*

Problem Tags: ['greedy', 'math'] 

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
        int f = 1;
        for(int i=1;i<n;i++){
            if(v[i]%v[0]!=0){
                f=0;
                break;
            }
        }
        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}

/*

a b c

c - xb - ya
c = xb + ya = xza + ya = a(xz + y)
d = lc + mb

b - za = 0

*/