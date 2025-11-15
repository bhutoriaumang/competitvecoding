/*

Problem Tags: ['dfs and similar', 'dp', 'greedy', 'math', 'math'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        string s;
        cin>>s;
        string m = "";
        for(int i=s.length()-1;i>=1;i--){
            for(int j=i-1;j>=0;j--){
                string k="";
                k.push_back(s[j]);
                k.push_back(s[i]);
                if(stoi(k)%25==0){
                    if(m.length()<=(j+2))
                        m = s.substr(0,j+1)+s[i];
                }
            }
        }
        cout<<(s.length()-m.length())<<endl;
    }
}