#include <iostream>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        int min;
        cin>>min;
        int a[n];
        a[0] = min;
        for(int i=1;i<n;i++){
            cin>>a[i];
            min = (min>a[i])?a[i]:min;
        }
        int c = 0;
        for(int i=0;i<n;i++){
            c+= ((a[i]==min)?1:0);
        }
        cout<<n-c<<"\n";
    }
}