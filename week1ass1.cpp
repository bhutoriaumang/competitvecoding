#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        long long int n,k;
        cin>>n>>k;
        long long int a[n];
        long double x1=-1,x2=-1;
        for(int i=0;i<n;i++){
            long long int x;
            cin>>x;
            x1 = (x1==-1)?((long double)(k*x)/(long double)(i+1)):(max(x1,(long double)(k*x)/(long double)(i+1)));
            x++;
            x2 = (x2==-1)?((long double)(k*x)/(long double)(i+1)):(min(x2,(long double)(k*x)/(long double)(i+1)));
        }
        if(floor(x2)==ceil(x2))
            x2-=1;
        cout<<(long long int)ceil(x1)<<" "<<(long long int)floor(x2)<<endl;
    }
}