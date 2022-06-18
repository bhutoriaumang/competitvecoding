#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector <int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        string ans = s,w="";
        int c = 0;
        while(w!=ans){
            c++;
            for(int i=0;i<n;i++)
                w+=s[v[i]-1];
            s = w;
            if(s==ans)
                break;
            w="";
        }
        cout<<c<<endl;
    }
}