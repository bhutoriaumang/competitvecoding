#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        string s;
        cin>>s;
        long long int ans = n;
        for(int i=0;i<n-1;i++){
            if(s[i]!=s[i+1]){
                ans+=i+1;
            }
        }
        cout<<ans<<endl;
    }
}

/*

1001

*/