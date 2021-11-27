#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    for(int i=0;i<5;i++){
        cout<<"*";
        for(int j=0;j<i;j++)
            cout<<" ";
        if(i>0)
            cout<<"*";
        cout<<endl;
    }
    for(int i=5;i>0;i--){
        cout<<i;
        for(int j=1;j<i;j++)
            cout<<" ";
        if(i>1)
            cout<<i;
        cout<<endl;
    }
}