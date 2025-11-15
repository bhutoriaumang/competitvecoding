/*

Problem Tags: ['constructive algorithms', 'math'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> x(n),v(n+1);
        for(int i=0;i<n;i++){
            cin>>x[i];
            v[x[i]] = i+1;
        }
        if((v[1]<v[n] && v[2]>v[n]) || (v[1]>v[n] && v[2]<v[n]))
            cout<<"1 1\n";
        else if(v[1]<v[n] && v[2]<v[n])
            cout<<max(v[1],v[2])<<" "<<v[n]<<endl;
        else if(v[1]>v[n] && v[2]>v[n])
            cout<<min(v[1],v[2])<<" "<<v[n]<<endl;
    }
}

/*

7 6 2 x 1 x x

1 n 2

1 3 5 2 4

*/