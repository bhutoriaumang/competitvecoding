#include <iostream>
using namespace std;

int main(){
    int n,m=1,c=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=1;i<n;i++){
        c++;
        if(a[i-1]>a[i]){
            if(c>=m)
                m = c;
            c = 0;
        }
    }
    if(c+1>m)
        m = c+1;
    cout<<m<<endl;
}