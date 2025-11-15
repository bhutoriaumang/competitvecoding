/*

Problem Tags: ['brute force', 'implementation', 'strings'] 

*/

#include <bits/stdc++.h>
using namespace std;

int up(int x){
    if(x==9)
        return 0;
    return x+1;
}

int down(int x){
    if(x==0)
        return 9;
    return x-1;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=0;i<n;i++){
            int c;
            cin>>c;
            string s;
            cin>>s;
            for(int j=0;j<c;j++){
                if(s[j]=='U')
                    v[i] = down(v[i]);
                else
                    v[i] = up(v[i]);
            }
        }
        for(int i=0;i<n;i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
}