#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n);
        int c = 0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            c+=(v[i]==2)?1:0;
        }
        long long int count = 0;
        for(int i=0;i<n;i++){
            count+= (v[i]==1)?(n-i-1):0;
            if(v[i]==2)
                count += (--c);
        }
        cout<<count<<endl;
    }
}