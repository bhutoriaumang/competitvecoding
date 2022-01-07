#include <bits/stdc++.h>
using namespace std;

int breakdown(string a,string b){

    if(a.length()==0)
        return 0;
    else if(a.length()>1){
        int x = stoi(a.substr(0,2));
        int y = x-((int)b[0] - 48);
        if(y<=9)
            return y + breakdown(a.substr(2),b.substr(1))*10;
    }
    int y = ((int)a[0] - 48) - ((int)b[0] - 48);
    return y + breakdown(a.substr(1),b.substr(1))*10;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        string s1,s2;
        cin>>s1>>s2;
        stack <int> a,b;
        for(int i=0;i<s1.length();i++)
            a.push((int)s1[i] - 48);
        for(int i=0;i<s2.length();i++)
            b.push((int)s2[i] - 48);
        string ans="";
        while(!a.empty()){
            if(b.empty()){
                b.push(-1);
                break;
            }
            int x = a.top();
            a.pop();
            int y = b.top();
            b.pop();
            if(!b.empty()){
                int z = b.top();
                b.pop();
                if(b.empty() && (z*10 + y - x) <19 && z!=0){
                    string k = to_string(z*10 + y - x);
                    reverse(k.begin(),k.end());
                    ans+=k;
                }
                else if((z*10 + y - x) <=9 && z!=0)
                    ans+= to_string(z*10 + y - x);
                else{
                    ans+= to_string(y-x);
                    b.push(z);
                }
            }
            else
                ans+= to_string(y-x);
        }
        reverse(ans.begin(),ans.end());
        if(!b.empty() && b.top()==0)
            b.pop();
        if(!b.empty())
            cout<<"-1\n";
        else{
            while(ans[0]=='0' && ans.length()>1)
                ans = ans.substr(1);
            cout<<ans<<"\n";
        }
    }
}