#include <bits/stdc++.h>
using namespace std;

int main(){
    int c=0,ans=0;
    for(int i=2;i<=100;i=pow(i,c)){
        c++;
        ans++;
    }
    cout<<ans<<endl;
}