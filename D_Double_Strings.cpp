/*

Problem Tags: ['brute force', 'data structures', 'strings'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <string> v(n);
        map <string,int> m;
        for(int i=0;i<n;i++){
            cin>>v[i];
            m[v[i]] = 1;
        }
        for(int i=0;i<n;i++){
            int f = 0;
            for(int j=0;j<v[i].length()-1;j++){
                string x = string(v[i].begin(),v[i].begin()+j+1);
                string y = v[i].substr(j+1);
                if(m.find(x)!=m.end() && m.find(y)!=m.end()){
                    f=1;
                    break;
                }
            }
            cout<<f;
        }
        cout<<endl;
    }
}