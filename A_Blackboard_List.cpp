#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        vector <long long int> v(n);
        long long int x=0,y=0;
        for(long long int i=0;i<n;i++){
            cin>>v[i];
            x = min(x,v[i]);
            y = max(y,v[i]);
        }
        if(x<0)
            cout<<x<<endl;
        else
            cout<<y<<endl;
    }
}