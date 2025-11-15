/*

Problem Tags: ['greedy'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        string s;
        cin>>s;
        int c1=0,c2=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='1')
                c1++;
            else
                c2++;
        }
        if(c1!=c2 && c1>0 && c2>0)
            cout<<min(c1,c2)<<endl;
        else if(c1==0 || c2==0)
            cout<<"0\n";
        else{
            if(s[s.length()-1]=='1')
                c1--;
            else
                c2--;
            cout<<min(c1,c2)<<endl;
        }
    }
}