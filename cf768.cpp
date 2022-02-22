#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,k;
        cin>>n>>k;
        int c = 0;
        int nn = n;
        vector <int> v(n);
        for(int i=0;i<n;i++)
            v[i] = i;
        while(nn>1){
            nn/=2;
            c++;
        }
        while(k>0){
            c--;
            if(k%2==0){
                int t = pow(2,c);
                cout<<t<<" "<<(n-t-1)<<endl;
                v[t] = -1;
                v[n-t-1] = -1;
            }
            
        }
    }
}

