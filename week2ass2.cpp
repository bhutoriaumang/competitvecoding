#include </Users/bits/stdc++.h>
using namespace std;

int maximum(vector <long long int> v){
    int m = 0;
    for(int i=0;i<v.size();i++){
        if(v[m]<v[i])
            m = i;
    }
    return m;
}

int main(){
    int t;
    cin>>t;
    while(t-->0){
        long long int n,M,u,ans;
        cin>>n>>M;
        vector <long long int> v(n);
        for(auto &i : v)
            cin>>i;
        ans = v[maximum(v)];
        u = ans;
        long long int l = 0;
        while(abs(l-u)>0){
            long long int m = (l+u)/2,s=0,ss=0;
            for(int j=0;j<n;j++){
                s+= ceil((double)v[j]/(double)m);
            }
            if(s<=M)
                u = m;
            else
                l = m+1;
        }
        cout<<l<<endl;
    }
}

/*
    {2   8   12}  {33  34  43  54}  {67  85}

*/