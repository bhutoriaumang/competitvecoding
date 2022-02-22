#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,a,b;
        cin>>n;
        vector <int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]==1)
                a = i;
            if(v[i]==n)
                b = i;
        }
        if(v[n-1]==1 || v[0]==n){
            cout<<"NO\n";
            continue;
        }
        else if(v[0]==1 || v[n-1]==n || a<b){
            cout<<"YES\n";
            continue;
        }
        int x = n+1,y=-1,f=0;
        for(int i=0;i<n;i++){
            if(i<b)
                x = min(x,v[i]);
            else if(i>a)
                y = max(y,v[i]);
        }
        if(x<y)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}


/*

3 2 4 6 1 5
4 3 5 1 2
1

6 1 2 3 4 5
4 2 3 6 1 5
*/