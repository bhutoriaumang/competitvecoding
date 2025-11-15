#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int a,b,ans;
        cin>>a>>b;
        if((a-1)%4==0)
            ans = a-1;
        else if((a-1)%4==1)
            ans = 1;
        else if((a-1)%4==2)
            ans = a;
        else if((a-1)%4==3)
            ans = 0;
        ans = ans^b;
        if(ans==a)
            cout<<(a+2)<<endl;
        else if(ans!=0)
            cout<<(a+1)<<endl;
        else
            cout<<(a)<<endl;
    }
}