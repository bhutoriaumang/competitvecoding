#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int x,y,ans=0;
        cin>>x>>y;
        ans+= (x-y);
        if(y%2){
            ans+=(y/2);
        }
        else{
            ans+=((y/2)-1);
        }
        cout<<ans*2<<endl;
    }
}