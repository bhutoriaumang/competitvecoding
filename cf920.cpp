#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        long long int n,m;
        cin>>n>>m;
        vector <long long int> a(n),b(m);
        for(long long int i=0;i<n;i++)
            cin>>a[i];
        for(long long int i=0;i<m;i++)
            cin>>b[i];
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),greater<long long int>());
        long long int i=0,j=0,ans=0;
        while((i+j)!=n){
            if(abs(a[i]-b[i]) >= abs(a[n-j-1]-b[m-j-1])){
                ans += abs(a[i]-b[i]);
                i++;
            }
            else{
                ans += abs(a[n-j-1]-b[m-j-1]);
                j++;
            }
        }
        cout<<ans<<endl;
    }
}