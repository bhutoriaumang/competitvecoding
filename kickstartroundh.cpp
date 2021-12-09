#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int c = 0;
        for(int i=0;i<n;i++){
            int j = i;
            while(s[j]=='R' || s[j]=='O' || s[j]=='P' || s[j]=='A')
                j++;
            if(i!=j)
                c++;
            i = j+1;
        }
        for(int i=0;i<n;i++){
            int j = i;
            while(s[j]=='Y' || s[j]=='O' || s[j]=='G' || s[j]=='A')
                j++;
            if(i!=j)
                c++;
            i = j+1;
        }
        for(int i=0;i<n;i++){
            int j = i;
            while(s[j]=='B' || s[j]=='G' || s[j]=='P' || s[j]=='A')
                j++;
            if(i!=j)
                c++;
            i = j+1;
        }
        cout<<"Case #"<<cas<<": "<<c<<endl;
    }
}