#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n);
        int x=-1;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(x==-1)
                x=v[0];
            else
                x=x&v[i];
        }
        int y=-1,ans=0;
        if(x==0){
            for(int i=n-1;i>=0;i--){
                y = (y==-1)?v[i]:(y&v[i]);
                if(y==x){
                    y = -1;
                    ans++;
                }
            }
        }
        else
            ans=1;
        cout<<ans<<endl;
    }
}