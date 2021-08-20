#include <bits/stdc++.h>
using namespace std;

int main(){
    vector <int> v;
    int t = 1,i=1;
    while(v.size()!=1000){
        if(i%3==0 || (i%10)==3){
            i++;
            continue;
        }
        v.push_back(i);
        i++;
    }
    cin>>t;
    while(t-->0){
        int k;
        cin>>k;
        cout<<v[k-1]<<"\n";
    }
}