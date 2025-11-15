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
        int l=-1,r=-1,f=0;
        for(int i=0;i<n;i++){
            int a=0,b=0;
            for(int j=i;j<n;j++){
                if(s[j]=='a')
                    a++;
                else
                    b++;
                if(a==b){
                    l = i+1;
                    r = j+1;
                    f = 1;
                    break;
                }
            }
            if(f)
                break;
        }
        cout<<l<<" "<<r<<endl;
    }
}