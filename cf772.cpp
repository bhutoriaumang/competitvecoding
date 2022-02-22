#include </Users/bits/stdc++.h>
using namespace std;

void display(vector <long long int> v ){
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

int count(long long int x){
    int c = 0;
    while(x>0){
        x/=2;
        c++;
    }
    return c;
}

int main(){
    int T;
    T = 1;
    while(T-->0){
        int n,p;
        cin>>n>>p;
        vector <long long int> v(n);
        long long int ans = 0,mod = 1e9 + 7;
        map <long long int , int> m;
        for(int i=0;i<n;i++){
            cin>>v[i];
            m[v[i]] = 1;
        }
        for(int i=0;i<n;i++){
            ans = (ans+1)%mod;
            long long int x = v[i];
            int flag = 0;
            queue <long long int> q;
            q.push(v[i]);
            
        }
        cout<<ans%mod<<endl;
    }
}