/*

Problem Tags: ['math'] 

*/

#include <bits/stdc++.h>
using namespace std;

void cal(int x,int a,int b,int c){
    if(x==a && x>b)
        cout<<"0 ";
    else if(x==a && x==b)
        cout<<"1 ";
    else if(x<a)
        cout<<(a-x+1)<<" ";
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int a,b,c;
        cin>>a>>b>>c;
        int m = max(max(a,b),c);
        int mi = min(min(a,b),c);
        int d = a+b+c-m-mi;
        cal(a,m,d,mi);
        cal(b,m,d,mi);
        cal(c,m,d,mi);
        cout<<endl;
    }
}