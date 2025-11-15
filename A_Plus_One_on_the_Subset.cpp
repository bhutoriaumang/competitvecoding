#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <long long int> v(n);
        long long int m = -1;
        for(int i=0;i<n;i++){
            cin>>v[i];
            m = max(m,v[i]);
        }
        long long int x = 0;
        for(int i=0;i<n;i++){
            x = max(x,m-v[i]);
        }
        cout<<x<<endl;
    }
}