#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n),x(n+1,0);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int s = n;
        for(int i=n-1;i>=0;i--){
            if(x[v[i]]!=0)
                break;
            x[v[i]]++;
            s--;
        }
        cout<<s<<endl;
    }
}