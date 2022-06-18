#include <bits/stdc++.h>
using namespace std;

int checkZero(int n,int k,string s,int c){
    if(c%2)
        return 0;
    int f = 1,count=0,cc=0;
    for(int i=0;i<n;i++){
        if(s[i]=='1')
            f = 0;
        if(f)
            count++;
        else if(cc%2==0 && s[i]=='0')
            count++;
        if(s[i]=='1'){
            cc++;
            c--;
        }
        if(cc%2==0 && cc!=0){
            count++;
            cc=0;
        }
    }
    if(count>=k)
        return 1;
    return 0;
}

int checkOne(int n,int k,string s,int c){
    if(c<k)
        return 0;
    c-=k;
    if(c%2)
        return 0;
    return 1;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        int c = 0;
        for(int i=0;i<n;i++)
            c+= (s[i]=='1')?1:0;
        if(checkZero(n,k,s,c) || checkOne(n,k,s,c))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}