#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        vector <long long int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        long long int s = 0;
        for(int i=0;i<n;i++)
            s+=v[i];
        double x = (double)((double)s / (double)n);
        if(floor(x)==ceil(x))
            cout<<"0\n";
        else
            cout<<"1\n";
    }
}