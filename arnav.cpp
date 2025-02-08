#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    vector <int> f(26,0);
    for(int i=0;i<s.length();i++){
        f[(int)s[i] - 97]++;
    }
    int index = -1,c=0;
    for(int i=0;i<26;i++){
        if(i==0 || i==4 || i==8 || i==14 || i==20){
            if(index==-1 || f[index] <= f[i])
                index = i;
        }
        else if(f[i]!=0)
            c++;
    }
    cout<<c<<endl;
    if(f[index]==s.length())
        cout<<"-1\n";
    else if(index==-1)
        cout<<(10*c)<<endl;
    else{
        int ans = 10*c + f[0]*abs(0-index);
        ans += f[4]*(4-index);
        ans += f[8]*(8-index);
        ans += f[14]*(14-index);
        ans += f[20]*(20-index);
        cout<<ans<<endl;
    }
}