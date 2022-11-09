#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        int n,k;
        cin>>n>>k;
        vector <int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        k*=2;
        int f = 1;
        for(int i=0;i<n;i++){
            int c=1;
            while(i<(n-1) && v[i]==v[i+1]){
                c++;
                i++;
            }
            if(c>2){
                f=0;
                break;
            }
            k-=c;
        }
        cout<<"Case #"<<cas<<": ";
        if(k>=0 && f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}