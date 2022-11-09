#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        int n,k;
        cin>>n>>k;
        vector <int> v(n,0),s(k);
        for(int i=0;i<k;i++)
            cin>>s[i];
        int t = 1;
        for(int i=k-1;i>0;i--){
            v[n-t] = s[i]-s[i-1];
            t++;
        }
        t = v[n-k+1];
        int c = n-k+1;
        
    }
}

/*

a b c d e f

a a+b a+b+c a+b+c+d a+b+c+d+e a+b+c+d+e+f




*/