#include </Users/bits/stdc++.h>
using namespace std;

string encoding(string s){
    int n = s.length();
    string w = "";
    for(int i=0;i<n;i++){
        w+=s[i];
        int c = 1;
        while(i<n-1 && s[i]==s[i+1]){
            i++;
            c++;
        }
        w+=to_string(c);
    }
    return w;
}

string decoding(string s){
    string w="";
    for(int i=0;i<s.length()-1;i+=2){
        int c = (int)(s[i+1]) - 48;
        while(c-->0)
            w+=s[i];
    }
    return w;
}


int main(){
    string s;
    cin>>s;
    cout<<decoding(s)<<endl;
}