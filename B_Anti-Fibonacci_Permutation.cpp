#include <bits/stdc++.h>
using namespace std;

void display(vector <int> v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n,0);
        for(int i=n;i>0;i--){
            v[n-i] = i;
        }
        display(v);
        for(int i=1;i<n;i++){
            swap(v[i],v[i-1]);
            display(v);
            swap(v[i],v[i-1]);
        }
    }
}

/*

4 3 2 1
4 3 1 2
4 2 3 1
3 4 2 1



*/