#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string w = "";
    for(int i=0;i<n;i++){
        w+= (char)(97+n-i-1);
        if(i!=(n-1))
            w+='-';
    }
    for(int i=1;i<n;i++){
        char c = (char)(97+i);
        w+= '-';
        w+=c;
    }
    for(int i=0;i<n;i++){
        string x = w.substr(0,(2*i + 1)) + w.substr((w.length())-(2*i));
        while(x.length() < w.length())
            x = "-"+x+"-";
        cout<<x<<endl;
    }
    for(int i=n-2;i>=0;i--){
        string x = w.substr(0,(2*i + 1)) + w.substr((w.length())-(2*i));
        while(x.length() < w.length())
            x = "-"+x+"-";
        cout<<x<<endl;
    }
}