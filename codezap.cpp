#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int n;
    cin>>n;
    vector <long long int> v(n);
    for(long long int i=0;i<n;i++)
        cin>>v[i];
    long long int a=0,b=0,aa=0,bb=0;
    for(long long int i=0;i<n;i++){
        if(i<(n/2)){
            if(i%2)
                a+=v[i];
            else
                b+=v[i];
        }
        else{
            if(i%2)
                aa+=v[i];
            else
                bb+=v[i];
        }
    }
    cout<<min(min(a+aa,b+bb),a+bb)<<endl;
}

/*


1 1 0 1 1 0 1 0 1

1 0 1 0

1 0 1 1 0 1
1 0 1 0 1 0
0 1 0 1 0 1


1 0 1 0 1 0 1
0 1 0 1 0 1 0
1 0 1 1 0 1 0

1 1 0 1 0 1

0 1 0 1 1 0




*/