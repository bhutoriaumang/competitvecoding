#include <iostream>
using namespace std;

int main(){
    long long n,c=0;
    cin>>n;
    int a[] = {100,20,10,5,1};
    for(int i=0;i<5;i++){
        c+=(int)n/a[i];
        n%=a[i];
    }
    cout<<c<<endl;
}