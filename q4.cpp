#include <iostream>
using namespace std;

int main(){
    int t;
    string s;
    cin>>s;
    cout<<s<<s.length()<<endl;
    return 0;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        int m = (int)n/2;
        cout<<a[m]<<" ";
        for(int i=1;i<m;i++){
            cout<<a[m+i]<<" "<<a[m-i]<<" ";
        }
        if(n%2==0)
            cout<<a[0];
        else
            cout<<a[n-1]<<" "<<a[0];
        cout<<endl;
    }
}