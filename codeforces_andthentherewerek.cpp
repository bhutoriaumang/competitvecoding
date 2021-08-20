#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t-->0){
        long long int n,nn;
        cin>>n;
        nn = n;
        long long int c = 0;
        while(nn>0){
            nn/=2;
            c++;
        }
        cout<<((long long int)pow(2,c-1)-1)<<endl;
    }
}