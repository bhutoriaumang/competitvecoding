#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        long long int n,f,a,b;
        cin>>n>>f>>a>>b;
        vector <long long int> v(n+1);
        v[0]=0;
        for(long long int i=0;i<n;i++)
            cin>>v[i+1];
        for(long long int i=1;i<n+1;i++){
            f -= min((v[i]-v[i-1])*a,b);
            if(f<=0)
                break;
        }
        if(f>0)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}