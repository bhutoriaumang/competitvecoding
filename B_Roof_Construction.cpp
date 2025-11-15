#include <bits/stdc++.h>
using namespace std;

int countbin(int x){
    int c = 1;
    while(x>1){
        c++;
        x/=2;
    }
    return c;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        int c = countbin(n-1);
        c = pow(2,c-1);
        vector <int> v;
        for(int i=0;i<n;i++)
            v.push_back(i);
        swap(v[0],v[c-1]);
        for(int i=0;i<n;i++)
            cout<<v[i]<<" ";
        cout<<endl;
    }
}