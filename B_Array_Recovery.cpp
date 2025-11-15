/*

Problem Tags: ['constructive algorithms', 'greedy', 'math'] 

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
        int f = 0;
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=1;i<n;i++){
            // cout<<v[i]<<" "<<v[i-1]<<endl;
            // cout<<f<<endl;
            if((v[i-1]-v[i])>=0 && v[i]!=0)
                f=1;
            v[i]+=v[i-1];
        }
        if(f)
            cout<<"-1\n";
        else{
            for(int i=0;i<n;i++)
                cout<<v[i]<<" ";
            cout<<endl;
        }
    }
}