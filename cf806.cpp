#include <bits/stdc++.h>
using namespace std;

long long int calc(vector <long long int> v,int c,int i,int k,int x){
    if(i==v.size()){
        return c;
    }
    long long int a = calc(v,c+(v[i]/pow(2,x-1))-k,i+1,k,x);
    long long int b = calc(v,c+(v[i]/pow(2,x)),i+1,k,x+1);
    if(a>b){
        return a;
    }
    else{
        return b;
    }
}

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        long long int n,k;
        cin>>n>>k;
        vector <long long int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        cout << calc(v,0,0,k,1) << endl;
    }
}

/*

10 10 3 1
0  1  0 0

5 10 11 11

10 10 29
5 5 14
5 2 7
5 2 3

5 5 14
5 2 7

*/