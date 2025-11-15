#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,k;
        cin>>n>>k;
        if(k>ceil((double)n/2.0)){
            cout<<"-1\n";
            continue;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i%2==0 && k>0 && j==i){
                    cout<<"R";
                    k--;
                }
                else
                    cout<<".";
            }
            cout<<"\n";
        }
    }
}