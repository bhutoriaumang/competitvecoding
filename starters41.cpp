#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n,k;
        cin>>n>>k;
        if(k==1){
            if(n%2==0)
                cout<<"EVEN\n";
            else
                cout<<"ODD\n";
        }
        else if(k==2)
            cout<<"ODD\n";
        else
            cout<<"EVEN\n";
    }
}