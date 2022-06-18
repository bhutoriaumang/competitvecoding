#include </Users/bits/stdc++.h>

using namespace std;

string convert(int n){
    string s = "";
    while(n>0){
        s = to_string(n%2) + s;
        n/=2;
    }
    return s;
}

int main(){
    for(int i =0;i<=100;i+=6)
        cout << convert(i) << endl;
}