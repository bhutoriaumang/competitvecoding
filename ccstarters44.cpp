#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n),x(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end(),greater<int>());
        long long int s = 0;
        for(int i=0;i<n;i++){
            s+= (n-v[i]);
            x.push_back(n-v[i]);
        }
        int k = 0,ss=0;
        for(int i=0;i<n;i++){
            if(v[k]>i){
                cout<<k<<" "<<(k+s);
            }
            else if(v[k]<i){
                k++;
                i--;
            }
            else{
                
            }
        }
    }
}