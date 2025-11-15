/*

Problem Tags: ['bitmasks', 'greedy'] 

*/

#include <bits/stdc++.h>
using namespace std;

vector <long long int> calc(vector <long long int> v,int x){
    int k = 0;
    while(x>0){
        v[k++] |= x%2;
        x/=2;
    }
    return v;
}
int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <long long int> ans(50,0),v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=0;i<n;i++){
            ans = calc(ans,v[i]);
        }
        long long int s = 0;
        for(int i=0;i<ans.size();i++){
            s+= pow(2,i)*ans[i];
        }
        cout<<s<<endl;
    }
}