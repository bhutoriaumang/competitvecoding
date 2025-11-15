#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        vector <long long int> a(n),b(n);
        long long int s1=0,s2=0,m1=1e9,m2=1e9;
        for(long long int i=0;i<n;i++){
            cin>>a[i];
            s1+=a[i];
            m1=min(m1,a[i]);
        }
        for(long long int i=0;i<n;i++){
            cin>>b[i];
            s2+=b[i];
            m2=min(m2,b[i]);
        }
        if((s1+n*m2)<(s2+n*m1))
            cout<<(s1+n*m2)<<endl;
        else
            cout<<(s2+n*m1)<<endl;
    }
}