/*

Problem Tags: ['binary search', 'greedy', 'greedy'] 

*/

#include <bits/stdc++.h>
using namespace std;
#define lli long long int

int main(){
    int T;
    cin>>T;
    while(T-->0){
        lli n,k;
        cin>>n>>k;
        vector <lli> v(k),s;
        for(int i=0;i<k;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        lli sum = 0;
        for(int i=k-1;i>=0;i--){
            sum+= n-v[i];
            s.push_back(sum);
        }
        reverse(s.begin(),s.end());
        int j = k-1;
        int m = 0;
        for(int i=0;i<k;i++){
            while(j>i && s[j]<v[i]){
                j--;
            }
            m = ((k-j)>m)?(k-j):m;
        }
        cout<<m<<endl;
    }
}