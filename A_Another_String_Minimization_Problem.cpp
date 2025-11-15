/*

Problem Tags: ['2-sat', 'constructive algorithms', 'greedy', 'string suffix structures', 'strings'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,m;
        cin>>n>>m;
        vector <int> v(n);
        vector <char> x(m+1,'B');
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=0;i<n;i++){
            if(x[v[i]]=='B' && v[i]<(m+1-v[i]))
                x[v[i]]='A';
            else if(x[m+1-v[i]]=='B' && v[i]>=(m+1-v[i]))
                x[m+1-v[i]]='A';
            else if(x[v[i]]=='B')
                x[v[i]]='A';
            else if(x[m+1-v[i]]=='B')
                x[m+1-v[i]]='A';
        }
        for(int i=1;i<=m;i++)
            cout<<x[i];
        cout<<endl;
    }
}