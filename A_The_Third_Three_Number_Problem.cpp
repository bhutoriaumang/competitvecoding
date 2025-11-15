#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        if(n%2==0){
            long long int x = n/2;
            x = x^1;
            cout<< "1 " << x << " " << x<<endl;
        }
        else{
            cout<<"-1\n";
        }
    }
}

/*

a^x + a^y + x^y
2 * (a^x)
a^x + a + x
a^1 + a + 1 = 1
a^1 + a = 0
n-x = a(1^x)

*/