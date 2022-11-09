#include <bits/stdc++.h>
using namespace std;

int fun(string s){
    int ans = 0,k=9,c=1;
    string w = "";
    vector <int> v(26,0);
    for(int i=0;i<s.length();i++){
        if(v[(int)s[i]-97]==0)
            w+=s[i];
        v[(int)s[i]-97]++;
    }
    sort(v.begin(),v.end(),greater<int>());
    for(int i=0;i<v.size();i++){
        if(v[i]==0)
            break;
        k--;
        ans += (v[i]*c);
        if(k==0){
            k=9;
            c++;
        }
        cout<<v[i]<<" "<<ans<<endl;
    }
    return ans;
}

int main(){
    cout << fun("abcdefghijklmnopqrstuvwxyz") << endl;
}