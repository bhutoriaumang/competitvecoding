/*

Problem Tags: ['greedy', 'implementation'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,c1=0,c2=0;
        cin>>n;
        string a,b;
        cin>>a>>b;
        for(int i=0;i<n;i++){
            if(a[i]=='1' && b[i]=='0'){
                c1++;
            }
            if(a[i]=='0' && b[i]=='1')
                c2++;
        }
        cout << (min(c1,c2) + abs(c1-c2)) << endl;
    }
}