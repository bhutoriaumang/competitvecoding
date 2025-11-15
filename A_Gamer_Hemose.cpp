#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n,h;
        cin>>n>>h;
        vector <long long int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end(),greater <long long int>());
        long long int c = h/(v[0]+v[1]);
        h -= c*(v[0]+v[1]);
        c*=2;
        if(h>0){
            h-=v[0];
            c++;
            if(h>0){
                h = 0;
                c++;
            }
        }
        cout<<c<<endl;
    }
}