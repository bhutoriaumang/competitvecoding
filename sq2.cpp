#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        int diff = v[1]-v[0];
        for(int i=1;i<n;i++)
            diff = min(diff,v[i]-v[i-1]);
        cout<<diff<<endl;
    }
}