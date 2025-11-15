/*

Problem Tags: ['greedy', 'implementation'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <long long int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        long long int f = 0,x=0,ff=0;
        for(int i=1;i<n-1;i++){
            if(v[i]%2==0)
                f = 1;
            if(v[i]%2 && v[i]>2)
                ff = 1;
            x += ceil((double)v[i]/2.0);
        }
        if(f)
            cout<<x<<endl;
        else{
            if(ff && n>=4)
               cout<<x<<endl;
            else
                cout<<"-1\n";
        }
    }
}