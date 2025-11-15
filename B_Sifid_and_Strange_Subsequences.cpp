#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector<long long int> v;
        int a[n],min = -1;
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>min)
                min = a[i];
            if(a[i]<=0)
                v.push_back(a[i]);
        }
        sort(v.begin(),v.end());
        int c=v.size();
        for(int i=0;i<c-1;i++){
            if(min==-1 || abs(v[i]-v[i+1])<min)
                min = abs(v[i]-v[i+1]);
        }
        if(c==0){
            min = a[0];
            for(int i=0;i<n;i++)
                min = (a[i]<min)?a[i]:min;
        }
        for(int i=0;i<n;i++){
            if(a[i]>0 && a[i]<=min){
                c++;
                break;
            }
        }
        cout<<c<<endl;
    }
}