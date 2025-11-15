#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int a,b,c,d;
        cin>>a>>b>>c>>d;
        if(b>d){
            cout<<"-1\n";
            continue;
        }
        int ans = abs(b-d);
        if((ans+a)<c)
            cout<<"-1\n";
        else
            cout<<(ans+abs(ans+a-c))<<endl;
    }
}