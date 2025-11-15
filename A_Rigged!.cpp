#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        pair <long long int,long long int> p1,p;
        cin>>p1.first>>p1.second;
        long long int f=1;
        for(long long int i=1;i<n;i++){
            cin>>p.first>>p.second;
            if(p1.first<=p.first && p1.second<=p.second)
                f = 0;
        }
        if(f)
            cout<<p1.first<<endl;
        else
            cout<<"-1"<<endl;
    }
}