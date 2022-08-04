#include <bits/stdc++.h>
using namespace std;

long long int mod = 1e9 + 7;
vector <long long int> fact(100001,1);

void factorial() {
    int factorial = 1;
    for(int i=2;i<=1e5;i++){
        fact[i] = ((fact[i-1]%mod) * i)%mod;
    }
}
 
int ncr(int n, int r) {
    return fact[n] / (fact[r] * fact[n-r]);
}

int main(){
    factorial();
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n),x(n,-1),y(n,-1),c(n,0);
        for(int i=0;i<n;i++)
            cin>>v[i];
        c[v[0]] = 1;
        c[v[n-1]] = 1;
        int k = v[0],l=v[n-1];
        for(int i=1;i<n;i++){
            if(v[i]<k){
                c[v[i]] = 1;
                k = v[i];
            }
            else
                x[i] = k;
        }
        for(int i=n-2;i>=0;i--){
            if(v[i]<l){
                c[v[i]] = 1;
                l = v[i];
            }
            else
                y[i] = l;
        }
        int s = 0;
        vector <int> d;
        for(int i=n-1;i>=0;i--){
            s+=c[i];
            c[i] = s;
        }
        for(int i=n-1;i>=0;i--){
            if(x[i]!=-1 && y[i]!=-1){
                d.push_back(n-c[max(x[i],y[i])]-max(x[i],y[i]));
            }
        }
        // for(int i=0;i<d.size();i++)
        //     cout<<d[i]<<" ";
        // cout<<endl;
        if(d.size()==0){
            cout<<"1\n";
        }
        else{
            long long int ans = 1;
            int count=0;
            for(int i=0;i<d.size();i++){
                int cc = 1;
                while(i<(d.size()-1) && d[i]==d[i+1]){
                    cc++;
                    i++;
                }
                if(i!=(d.size()-1)){
                    long long int temp = ((ncr((d[d.size()-1]-cc),d[i]-cc)%mod) * (fact[d[i]-count]%mod))%mod;
                    ans = ((ans%mod)*(temp%mod))%mod;
                }
                else
                    ans = ((ans%mod)*(fact[d[i]-count]%mod))%mod;
                count+=d[i];
            }
            cout<<ans<<endl;
        }
    }
}

/*

x : -1 1 1 1 1 -1 0 0 
y : 0 0 0 0 0 -1 4 -1 

    x 1 1 1 1 x 4 x

5 5 5 5 3

6*6*2

c : 3 2 1 1 1 0 0 0

4 * 4 * 3 * 2

0 3 5 7

2 4 6
2 4 6
4 6
4 6

2!

4 0 3 2 1

4 : 0
0 : 1
3 : 0
2 : 0
1 : 0

4 0 : 1
0 3 : 1
3 2 : 0
2 1 : 0

4 0 3 : 1
0 3 2 : 1
3 2 1 : 0

4 0 3 2 : 1
0 3 2 1 : 4

4 0 a a 1

0 1 2 3

0 1 2 3

1 3 7 2 5 0 6 4

1 (>1) (>1) (>0) (>0) 0 (>4) 4

[2,3,5,6,7] [5,6,7]

4C2*2!*3!

6*6*2

1 2 4 0 5 3

1 (>1) (>1) 0 (>3) 3

 [2,4,5] [4,5]

 2c1 * 2!

 

*/