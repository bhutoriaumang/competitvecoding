#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,k;
        cin>>n>>k;
        vector <int> v(n);
        int x = -1;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]==0)
                x = i;
        }
        int d = 2;
        v[x] = -1;
        while(d<=n){
            if((x-k)>=0){
                for(int j=1;j<=k;j++){
                    if(v[x-j]==)
                }
            }
        }
    }
}