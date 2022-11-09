#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> f(n,0),v(n,-1);
        int x = (int)sqrt((n-1)*2),fl=1;
        for(int i=n-1;i>=0;i--){
            for(int j=x;j>=0;j--){
                int t = (j*j) - i;
                if(t<n && f[t]==0){
                    v[i]=t;
                    f[t]=1;
                    break;
                }
            }
            if(v[i]==-1){
                fl=0;
                break;
            }
        }
        if(!fl){
            cout<<"-1\n";
            continue;
        }
        for(int i=0;i<n;i++){
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}

/*

0
1 0
1 0 2
0 3 2 1
4 3 2 1 0
0 3 2 1 5 4
1 0 2 6 5 4 3
1 0 7 6 5 4 3 2


0 -> 1
1 -> 1
2 -> 9
3 -> 9
4 -> 9
5 -> 9
6 -> 9
7 -> 9

*/