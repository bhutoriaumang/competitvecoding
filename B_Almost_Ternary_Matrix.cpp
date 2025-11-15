/*

Problem Tags: ['bitmasks', 'constructive algorithms', 'matrices'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,m;
        cin>>n>>m;
        vector < vector <int> > a(n,vector <int>(m,0));
        int x = 1,c=0,f=1;
        for(int i=0;i<n-1;i+=2){
            for(int j=0;j<m-1;j+=2){
                a[i][j] = x;
                a[i+1][j] = x^1;
                a[i+1][j+1] = x;
                a[i][j+1] = x^1;
                x = 1^x;
                c++;
            }
            f^=1;
            x = f;
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
        // cout<<"\n";
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         int c = 0;
        //         if(i-1>=0 && a[i-1][j]!=a[i][j])
        //             c++;
        //         if(j-1>=0 && a[i][j-1]!=a[i][j])
        //             c++;
        //         if(i+1<n && a[i+1][j]!=a[i][j])
        //             c++;
        //         if(j+1<m && a[i][j+1]!=a[i][j])
        //             c++;
        //         if(c==2)
        //             cout<<"1 ";
        //         else
        //             cout<<"0 ";
        //     }
        //     cout<<endl;
        // }
    }
}

/*

a^x + a^y + x^y
2 * (a^x)
a^x + a + x
a^1 + a + 1 = 1
a^1 + a = 0
n-x = a(1^x)

100110
011001
011001
100110

*/