/*

Problem Tags: ['greedy', 'strings'] 

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        string s;
        cin>>s;
        int t = 0,ans=0;
        for(char c='a';c<='z';c++){
            int co = 0;
            for(int i=0;i<s.length();i++){
                if(s[i]==c)
                    co++;
            }
            if(co>=2)
                ans++;
            else
                t+=co;
        }
        ans+=(t/2);
        cout<<ans<<endl;
    }
}