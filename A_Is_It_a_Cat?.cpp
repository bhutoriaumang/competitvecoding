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
        string s;
        cin>>s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        string x = "meow";
        int ind=0;
        for(int i=0;i<n;i++){
            if(ind==4){
                ind++;
                break;
            }
            while(i<(n-1) && s[i]==s[i+1]){
                i++;
            }
            if(x[ind]!=tolower(s[i]))
                break;
            ind++;
        }
        if(ind!=4)
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
}