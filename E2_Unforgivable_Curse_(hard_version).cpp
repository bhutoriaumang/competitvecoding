/*

Problem Tags: ['brute force', 'constructive algorithms', 'dfs and similar', 'dsu', 'graphs', 'greedy', 'strings'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,k;
        cin>>n>>k;
        string x,y;
        cin>>x>>y;
        int f=1;
        vector <int> v(26,0);
        for(int i=0;i<n;i++){
            v[(int)x[i]-97]++;
            v[(int)y[i]-97]--;
            if((i-k)<0 && (i+k)>=n && x[i]!=y[i]){
                f=0;
                break;
            }
        }
        for(int i=0;i<26;i++){
            if(v[i]!=0){
                f=0;
                break;
            }
        }
        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}

/*

1 2 3 4 5 6 7 8 9 10

1 4 5 7 8 9 10
2 5 6 8 9 10

2 5 6
6 5 2
5 6 2
2 6 5

fcgjy
fygjc
cygjf
cfgjy

*/