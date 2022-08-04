#include <bits/stdc++.h>
using namespace std;

int main(){
	int T;
    cin>>T;
    while(T-->0){
        long long int n,q;
        cin>>n>>q;
        vector <long long int> v(n),w(n,1);
        for(long long int i=0;i<n;i++)
            cin>>v[i];
        
    }
}

/*

a b c d e f

b-a, c-b, d-c, e-d, f-e

(c-b)-(b-a), (d-c)-(c-b), (e-d)-(d-c), (f-e)-(e-d)
c+a-2b, d+b-2c, e+c-2d, f+d-2e

a-3b-d+3c, b+d+e
(a-d)-3(b-c), (b-e)-3(c-d), (c-f)-3(d-e)

a b c d e f
b-a,c-b,d-c,e-d,f-e
c+a-2b,d+b-2c,e+c-2d,f-2e+d
d+3b-3c-a,e+3c-3d-b,f-3e+3d-c
e-4d+6c-4b+a,f-4e+6d-4c+b
f-5e+10d-10c+5b-a,g-5f+10e-10d+5c-b
g-6f

*/