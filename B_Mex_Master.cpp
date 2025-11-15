/*

Problem Tags: ['constructive algorithms', 'greedy'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n);
        int c=0,mini=1e6,maxi=-1;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]==0)
                c++;
            if(v[i]!=0)
                mini = min(mini,v[i]);
            maxi = max(maxi,v[i]);
        }
        if(c==n){
            cout<<"1\n";
            continue;
        }
        if(c<=ceil((double)n/2.0)){
            cout<<"0\n";
            continue;
        }
        if(mini!=maxi){
            cout<<"1\n";
        }
        else if(mini==1)
            cout<<"2\n";
        else
            cout<<"1\n";
    }
}