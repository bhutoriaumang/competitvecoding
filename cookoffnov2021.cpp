#include </Users/bits/stdc++.h>
using namespace std;

long long int optelement(vector <long long int> v, int x, int y){
    auto it = upper_bound(v.begin()+x+1,v.begin()+y,(v[x]+v[y])/2);
    long long int m = -INT_MAX;
    if(it!=v.begin()+y)
        m = max(m,(long long int)(v[y]-*it)*(long long int)(*it - v[x]));
    else if(--it!=v.begin()+x)
        m = max(m,(long long int)(v[y]-*it)*(long long int)(*it - v[x]));
    return m;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        vector <long long int> v(n);
        for(long long int i=0;i<n;i++)
            cin>>v[i];
        if(n==3){
            cout<<(v[2]-v[1])*(v[1]-v[0])<<endl;
            continue;
        }
        long long int s = 0;
        for(int i=0;i<n;i++){
            for(int j=i+2;j<n;j++){
                s+= optelement(v,i,j);
            }
        }
        cout<<s<<endl;
    }
}