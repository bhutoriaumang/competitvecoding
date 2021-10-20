#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        long long int sum=0,k=1;
        while(true){
            sum+=k;
            k*=2;
            if((sum+k)>n)
                break;
        }
        cout<<max(k/2,n-sum)<<endl;
    }
}