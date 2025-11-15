/*

Problem Tags: ['brute force', 'greedy', 'math', 'strings'] 

*/

#include <bits/stdc++.h>
using namespace std;
long long int m = 1000000000 + 7;

void check(string s,char c){
    int f = -1;
    s = " "+s;
    for(int i=2;i<s.length();i++){
        int j = i,co=0;
        while(j<s.length()){
            if(s[j]!=c)
                co++;
            j+=i;
        }
        if(co==0){
            cout<<"1\n"<<i<<endl;
            return;
        }
    }
    cout<<"2\n"<<(s.length()-2)<<" "<<(s.length()-1)<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        int f = 1;
        for(int i=0;i<s.length();i++){
            if(s[i]!=c){
                f = 0;
                break;
            }
        }
        if(f){
            cout<<"0\n";
            continue;
        }
        check(s,c);
    }
}