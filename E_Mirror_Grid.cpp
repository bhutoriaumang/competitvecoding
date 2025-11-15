#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector < vector <int> > v(n,vector<int>(n));
        for(int i=0;i<n;i++){
            string t;
            cin>>t;
            for(int j=0;j<n;j++)
                v[i][j] = (int)t[j]-48;
        }
        int ans = 0;
        for(int i=0;i<n-1;i++){
            for(int j=i;j<n-i-1;j++){
                int a = v[i][j];
                int b = v[j][n-i-1];
                int c = v[n-i-1][n-j-1];
                int d = v[n-j-1][i];
                int x = a+b+c+d;
                ans += min(x,4-x);
            }
        }
        cout<<ans<<endl;
    }
}

/*

xxxxxx
xxxxxx
xxxxxx
xxxxxx
xxxxxx
xxxxxx

00 01 02 03 04
10 11 12 13 14
20 21 22 23 24
30 31 32 33 34
40 41 42 43 44

*/