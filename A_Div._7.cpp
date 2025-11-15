#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        if(n%7==0)
            cout<<n<<endl;
        else{
            int x = n - n%7;
            if(x<((n/10)*10))
                x = n + (7-n%7);
            cout<<x<<endl;
        }
    }
}