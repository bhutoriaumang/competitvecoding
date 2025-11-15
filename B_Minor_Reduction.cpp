/*

Problem Tags: ['greedy', 'strings'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T-->0){
        string s;
        cin>>s;
        int x = 0;
        for(int i=0;i<s.length()-1;i++){
            int k =(((int)s[i]-48) + ((int)s[i+1]-48));
            if(k>=10)
                x = i;
        }
        string w = "";
        w = s.substr(0,x)+to_string(((int)s[x]-48) + ((int)s[x+1]-48))+s.substr(x+2);
        cout<<w<<"\n";
    }
}