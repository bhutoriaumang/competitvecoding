/*

Problem Tags: ['data structures', 'dp', 'implementation'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    T=1;
    while(T-->0){
        long long int n,m;
        cin>>n>>m;
        vector <long long int> v(n),a(n),b(n);
        for(long long int i=0;i<n;i++)
            cin>>v[i];
        a[0]=0;
        b[n-1]=b[0];
        for(long long int i=1;i<n;i++){
            a[i] = max((long long int)0,v[i-1]-v[i]);
            if(i>0)
                a[i]+=a[i-1];
        }
        for(long long int i=n-2;i>=0;i--){
            b[i] = max((long long int)0,v[i+1]-v[i]);
            if(b[i]!=(n-1))
                b[i]+=b[i+1];
        }
        for(long long int i=0;i<m;i++){
            long long int x,y;
            cin>>x>>y; 
            if(x<y){
                cout<<(a[y-1]-a[x-1])<<endl;
            }
            else{
                cout<<(b[y-1]-b[x-1])<<endl;
            }
        }
        // for(long long int i=0;i<n;i++){
        //     cout<<a[i]<<" "<<b[i]<<endl;
        // }
    }
}
/*


2 5 1 10 4


*/