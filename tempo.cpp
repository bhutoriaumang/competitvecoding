#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main(){
    int n,w,s=0;
    cin>>n>>w;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
        s+=a[i];
    }
    w = s-w;
    int f = n-1;
    while(w>0){
        w-=a[f--];
    }
    while(f>=0)
        cout<<a[f--]<<"\t";
    cout<<endl;
}