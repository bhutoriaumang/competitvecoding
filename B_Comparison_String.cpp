/*

Problem Tags: ['greedy'] 

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
        int c=1,x=0;
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1])
                c++;
            else{
                x = max(x,c);
                c=1;
            }
        }
        x = max(x,c);
        cout<<x+1<<endl;
    }
}