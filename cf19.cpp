#include <bits/stdc++.h>
using namespace std;

long long int calc(vector <long long int> v,int n){
    long long int sum = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++)
            sum+= ((v[i]+v[j])*(v[i]+v[j]));
    }
    return sum;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <long long int> a(n),b(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n;i++)
            cin>>b[i];
        long long int ans = calc(a,n)+calc(b,n);
        for(int i=0;i<n-1;i++){
            swap(a[i],b[i]);
            long long int x = calc(a,n)+calc(b,n);
            if(x>=ans){
                swap(a[i],b[i]);
            }
            else
                ans = x;
        }
        cout<<ans<<endl;
    }
}