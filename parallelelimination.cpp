#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        string s = "";
        if(n%2){
            s = "b";
            n/=2;
            for(int i=0;i<n;i++)
                s = "a"+s+"a";
        }
        else{
            s = "bb";
            n/=2;
            for(int i=1;i<n;i++)
                s = "a"+s+"a";
        }
        cout<<s<<endl;
    }
}