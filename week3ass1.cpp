#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        string s;
        cin>>s;
        int n= s.length();
        int c=0,k=0;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                k++;
                if(i>0 && s[i-1]=='0'){
                    s[i-1] = '2';
                    c++;
                }
                else if(i<(n-1) && s[i+1]=='0'){
                    s[i+1] = '2';
                    c++;
                }
            }
        }
        if((n-k-c)<k)
            cout<<"1\n";
        else if((n-k-c)==k)
            cout<<"-1\n";
        else
            cout<<"0\n";
    }
}