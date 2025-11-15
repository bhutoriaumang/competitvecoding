#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> a(n),b(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        int m1=0,m2=0;
        for(int i=0;i<n;i++){
            if(a[i]<b[i])
                swap(a[i],b[i]);
            m1=max(a[i],m1);
            m2=max(b[i],m2);
        }
        cout<<m1*m2<<endl;
    }
}