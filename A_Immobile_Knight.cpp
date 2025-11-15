/*

Problem Tags: ['implementation'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,m;
        cin>>n>>m;
        if(n<=3 && m<=3)
            cout<<ceil((double)n/2.0)<<" "<<ceil((double)m/2.0)<<endl;
        else
            cout<<n<<" "<<m<<endl;
    }
}

// x x x x
// x x x x