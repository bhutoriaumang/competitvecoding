/*

Problem Tags: ['constructive algorithms', 'greedy'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        string s;
        cin>>s;
        int x=-1;
        char t=(s[0]=='?')?'0':s[0];
        vector <char> w(s.length());
        for(int i=0;i<s.length();i++){
            if(s[i]=='?')
                w[i]=t;
            else{
                w[i]=s[i];
                t=s[i];
            }
        }
        for(int i=0;i<w.size();i++)
            cout<<w[i];
        cout<<endl;
    }
}