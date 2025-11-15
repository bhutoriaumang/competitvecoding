/*

Problem Tags: ['dp', 'greedy'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];
        int c = 0,k=1,i=n-2;
        while(i>=0){
            while(i>=0 && a[i]==a[n-1]){
                i--;
                k++;
            }
            if(i<0)
                break;
            c++;
            i = i-k;
            k*=2;
        }
        cout<<c<<endl;
    }
}

