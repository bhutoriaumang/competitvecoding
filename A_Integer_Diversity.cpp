/*

Problem Tags: ['implementation'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n),ans(201,0);
        vector <int> x;
        int s=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(find(x.begin(),x.end(),v[i])==x.end()){
                s++;
                x.push_back(v[i]);
            }
            else if(find(x.begin(),x.end(),-v[i])==x.end()){
                s++;
                x.push_back(-v[i]);
            }
        }
        cout<<s<<endl;
    }
}