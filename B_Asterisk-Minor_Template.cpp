/*

Problem Tags: ['implementation', 'strings'] 

*/

#include <bits/stdc++.h>
using namespace std;

string printLCSubStr(string X, string Y, int m, int n)
{
    int LCSuff[m + 1][n + 1];
    int len = 0;
    int row, col;
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                if (len < LCSuff[i][j]) {
                    len = LCSuff[i][j];
                    row = i;
                    col = j;
                }
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    if (len == 0) {
        return "";
    }
    string resultStr = "";
    while (LCSuff[row][col] != 0) {
        resultStr = X[row - 1] + resultStr;
        row--;
        col--;
    }
    return resultStr;
}

vector <string> calc(string x){
    vector <string> t;
    for(int i=0;i<x.length();i++){
        string s = "";
        for(int j=i;j<x.length();j++){
            s+=x[j];
            if(s.length()>1)
                t.push_back("*"+s+"*");
            // cout<<"*"<<s<<"*"<<endl;
            if(j==(x.length()-1)){
                // cout<<"*"<<s<<endl;
                t.push_back("*"+s);
            }
            if(i==0){
                // cout<<s<<"*"<<endl;
                t.push_back(s+"*");
            }
            if(i==0 && j==(x.length()-1)){
                t.push_back(s);
                // cout<<s<<endl;
            }
        }
    }
    return t;
}

bool check(string x){
    int c = 0;
    for(int i=0;i<x.length();i++){
        if(x[i]=='*')
            c++;
    }
    if(c>(x.length()-c))
        return false;
    return true;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        string s,w;
        cin>>s>>w;
        if(s.length()<w.length())
            swap(s,w);
        string x = printLCSubStr(s,w,s.length(),w.length());
        if(x.length()==0){
            cout<<"NO\n";
            continue;
        }
        else if(x.length()==1 && s[0]!=w[0] && s[s.length()-1]!=w[w.length()-1] ){
            cout<<"NO\n";
            continue;
        }
        else if(x.length()==1 && (s[0]==w[0])){
            cout<<"YES\n";
            cout<<s[0]<<"*\n";
        }
        else if(x.length()==1 && (s[s.length()-1]==w[w.length()-1])){
            cout<<"YES\n";
            cout<<"*"<<s[s.length()-1]<<"\n";
        }
        else{
            cout<<"YES\n";
            cout<<"*"<<x<<"*\n";
        }
    }
}