/*

Problem Tags: [] 

*/

#include <bits/stdc++.h>
using namespace std;

int func(long long int l, double x){
    return floor((double)l/(double)x);
}

int main(){
    int n,k;
    cin>>n>>k;
    vector <long long int> v(n);
    long long int sum = 0;
    for(int i=0;i<n;i++){
        cin>>v[i];
        sum+=v[i];
    }
    double u = 1e9,l=0,m;
    for(int i=0;i<100;i++){
        m = (l+u)/2;
        int c = 0;
        for(int i=0;i<n;i++)
            c+=func(v[i],m);
        if(c>=k)
            l = m;
        else
            u = m;
    }
    cout<<fixed<<setprecision(20)<<l<<endl;
}