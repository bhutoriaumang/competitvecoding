#include <bits/stdc++.h>
using namespace std;

vector <string> calc(string s,int n){
    vector <int> v(26,0),xx;
    string x = "";
    for(int i=0;i<n;i++){
        v[(int)s[i] - 97]++;
    }
    for(int i=0;i<26;i++){
        if(v[i]==0)
            xx.push_back(i);
        x+= (v[i]%2==1)?"1":"0";
    }
    vector <string> ans;
    ans.push_back(x);
    for(int i=0;i<xx.size();i++){
        x.replace(xx[i],1,"3");
        ans.push_back(x);
        x.replace(xx[i],1,"0");
    }
    return ans;
}

string complement(string x,int n){
    string s = "";
    for(int i=0;i<n;i++){
        if(x[i]=='3')
            s+='3';
        else
            s+= (x[i]=='1')?"0":"1";
    }
    return s;
}

int main(){
    int n,ans = 0;
    cin>>n;
    vector <string> v(n),x;
    unordered_map <string,int> m;
    for(int i=0;i<n;i++){
        cin>>v[i];
        vector <string> temp = calc(v[i],v[i].length());
        for(int i=0;i<temp.size();i++){
            x.push_back(temp[i]);
            if(m.find(temp[i])==m.end()){
                m.insert(make_pair(temp[i],1));
            }
            else
                m[temp[i]]++;
        }
    }
    for(int i=0;i<x.size();i++){
        string t = complement(x[i],x[i].length());
        if(m.find(t)!=m.end()){
            ans += m[t];
        }
        m[x[i]]--;
    }
    cout<<ans<<endl;
}

/*

1 2 3 4 5 6 7 8 9 10

1 4 5 7 8 9 10
2 5 6 8 9 10

2 5 6
6 5 2
5 6 2
2 6 5

fcgjy
fygjc
cygjf
cfgjy

abcdefghijklmnopqrstuvwxy

00000100000100000001000000
11111111111111111111111110
11111011111011111110111110
11111011111011111110111111
00000100000100000001000000
00000000000000000000000000
00000001100100000001010000
01111110011111111110101111
01101010001100100010010000
11111110000000000000000000
00000000111111111111101111

11111011111011111110111113
11111101110111111110111113

*/