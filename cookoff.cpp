#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        long long int k,n;
        cin>>k>>n;
        vector < vector <long long int> > v(k, vector <long long int> (n,0));
        vector <long long int> x;
        for(long long int i=0;i<k;i++){
            for(long long int j=0;j<n;j++){
                cin>>v[i][j];
                x.push_back(v[i][j]);
            }
        }
        sort(x.begin(),x.end(),greater<long long int>());
        long long int a=0,b=0;
        for(long long int i=0;i<x.size();i++){
            if(a<b)
                a+=x[i];
            else
                b+=x[i];
            // cout<< a << " " << b << " : " << x[i]<<endl;
        }
        cout<<abs(a-b)<<endl;
    }
}

/*


1 2 3 4 5 6 7 8 9 10

*/