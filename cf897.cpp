#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        vector <long long int> v(n);
        for(long long int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        long long int y = v[n-1]+1;
        if(v[0]==0)
            y = 0;
        while(true){
            cout<<y<<endl;
            cin>>y;
            cout.flush();
            if(y<0){
                break;
            }
        }
    }
}