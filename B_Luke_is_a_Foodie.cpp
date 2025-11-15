#include <bits/stdc++.h>
using namespace std;

int intersect(long long int a,long long int b,long long int x,long long int y){
    if(a<=x && x<=b)
        return 1;
    if(x<=a && a<=y)
        return 1;
    return 0;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n,x;
        cin>>n>>x;
        vector <long long int> v(n),a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            a[i] = v[i]-x;
            b[i] = x+v[i];
        }
        int c=0;
        // for(int i=0;i<n;i++)
        //     cout<<a[i]<<" ";
        // cout<<endl;
        // for(int i=0;i<n;i++)
        //     cout<<b[i]<<" ";
        // cout<<endl;
        for(int i=0;i<n-1;i++){
            if(intersect(a[i],b[i],a[i+1],b[i+1])){
                // cout<<i<<" HI\n";
                a[i+1] = max(a[i],a[i+1]);
                b[i+1] = min(b[i],b[i+1]);
            }
            else{
                // cout<<i<<" HELLO\n";
                c++;
            }
        }
        cout<<c<<endl;
    }
}