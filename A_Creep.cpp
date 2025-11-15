/*

Problem Tags: ['greedy', 'implementation'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int a,b;
        cin>>a>>b;
        int x = a+b;
        string w = "";
        for(int i=0;i<x;i++){
            if(a>0 && b>0){
                a--;
                w+="0";
                b--;
                w+="1";
            }
        }
        while(a-->0){
            w += "0";
        }
        while(b-->0){
            w += "1";
        }
        cout<<w<<endl;
    }
}

/*



*/