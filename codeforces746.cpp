#include </Users/bits/stdc++.h>
using namespace std;
#define lli long long int

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,x;
        cin>>n>>x;
        vector <lli> v(n),a;
        for(int i=0;i<n;i++){
            cin>>v[i];
            a.push_back(v[i]);
        }
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            int t = find(a.begin(),a.end(),v[i]) - a.begin();
            a[t] = -1;
            v[i] = t;
        }
        int f = 1;
        for(int i=0;i<n-1;i++){
            int t = abs(i-v[i]);
            if(t==0)
                continue;
            else if(t>=x){
                swap(v[i],v[v[i]]);
            }
            else{
                if((v[i]+x)<n)
                    swap(v[i],v[v[i]]);
                else if((i-x)>=0)
                    swap(v[i],v[v[i]]);
                else{
                    f = 0;
                    break;
                }
            }
        }
        if(f)
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
}

/*

8 1 5 2 3 6 7 4 9 0
0 1 5 2 3 6 7 4 9 8




*/