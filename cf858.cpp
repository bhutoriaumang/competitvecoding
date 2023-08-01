#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        vector <long long int> v(2*n);
        long long int s = 0,sum=0;
        for(long long int i=0;i<2*n;i++){
            cin>>v[i];
            sum+=abs(v[i]);
        }
        sort(v.begin(),v.end());
        long long int x = ceil((double)sum / (double)(2*n));
        long long int y = floor((double)sum / (double)(2*n));
        long long int ans = 0;
        for(long long int i=0;i<2*n;i++)
            s += abs(v[i]-x);
        ans = s;
        s=0;
        for(long long int i=0;i<2*n;i++)
            s += abs(v[i]-y);
        ans = min(ans,s);
        s=0;
        if(n%2==0){
            for(long long int i=0;i<(2*n)-1;i++)
                s+= abs(-1-v[i]);
            s += abs(n-v[(2*n)-1]);
            ans = min(ans,s);
        }
        cout<<ans<<endl;
    }
}

/*

a b c d
aa+ab = ac*d
a*b = c+d

aa = acd - c - d
c+d = a(cd-a)

a+b=cd
a+c=bd
a+d=bc
b+c=ad
b+d=ac

3a+3b+2c+2d = ac+ad+bc+bd+cd
2a+2b+3c+3d = ab+ac+ad+bc+bd

5(a+b+c+d) = 2ac+2ad+2bc+2bd+ab+cd

2 2 2 2

1 1 1 2



*/