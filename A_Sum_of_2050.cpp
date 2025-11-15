/*

Problem Tags: ['greedy', 'math'] 

*/

#include <iostream>
using namespace std;

int main(){
    long long t;
    cin>>t;
    for(long long ca=0;ca<t;ca++){
        long long n;
        cin>>n;
        if(n%2050!=0){
            cout<<"-1"<<endl;
            continue;
        }
        long long x = n/2050;
        long long s =0 ;
        while(x>0){
            s+=x%10;
            x/=10;
        }
        cout<<s<<endl;
    }
}

/*
    2050(1 + 1 +  100 + 10000)
*/