#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n;
        cin>>n;
        if(n==1){
            cout<<"1\n";
            continue;
        }
        vector <long long int> v;
        for(long long int i=1;(long long int)(i*i)<=n;i++)
            v.push_back((long long int)(i*i));
        for(long long int i=1;(long long int)(i*i*i)<=n;i++)
            v.push_back((long long int)(i*i*i));
        sort(v.begin(),v.end());
        int count = 0;
        for(int i=0;i<v.size()-1;i++){
            count++;
            while(i<(v.size()-1) && v[i]==v[i+1]){
                i++;
            }
        }
        if(v[v.size()-1]!=v[v.size()-2])
            count++;
        cout<<count<<endl;
    }

}