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
        if(n==1){
            cout<<"0\n";
            continue;
        }
        if(n==2){
            cout<<"1\n";
            continue;
        }
        int c = 0;
        for(int i=1;i<n;i++){
            if(i<n-1 && v[i]==v[i+1] && v[i-1]==v[i]){
                c++;
                v[i]=-1;
                i++;
            }
            else if(v[i-1]==v[i]){
                v[i]=-1;
                c++;
            }
        }
        if(v[n-1]==v[n-2] && v[n-2]!=v[n-3])
            c++;
        cout<<c<<endl;
    }
}