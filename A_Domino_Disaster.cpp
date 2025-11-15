/*

Problem Tags: ['implementation', 'strings'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        string s,w="";
        cin>>s;
        for(int i=0;i<n;i++){
            if(s[i]=='L' || s[i]=='R')
                w+=s[i];
            else
                w+= (s[i]=='U')?'D':'U';
        }
        cout<<w<<endl;
    }
}