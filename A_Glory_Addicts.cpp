#include <bits/stdc++.h>
using namespace std;

int main(){
    long long int T;
    cin>>T;
    while(T-->0){
        long long int n,sum=0;
        cin>>n;
        vector <long long int> a(n),b(n),x,y;
        for(long long int i=0;i<n;i++)
            cin>>a[i];
        for(long long int i=0;i<n;i++)
            cin>>b[i];
        for(long long int i=0;i<n;i++){
            if(a[i])
                x.push_back(b[i]);
            else
                y.push_back(b[i]);
            sum+=b[i];
        }
        if(x.size()==0 || y.size()==0){
            cout<<sum<<endl;
            continue;
        }
        sort(x.begin(),x.end(),greater <long long int> ());
        sort(y.begin(),y.end(),greater <long long int> ());
        long long int ans1=x[x.size()-1],ans2=y[y.size()-1];
        long long int c = min(x.size(),y.size());
        for(long long int i=0;i<x.size();i++){
            if(c>0){
                if(i!=(x.size()-1))
                    ans1+=(2*x[i]);
                ans2+=(2*x[i]);
            }
            else{
                if(i!=(x.size()-1))
                    ans1+=(x[i]);
                ans2+=(x[i]);
            }
            c--;
        }
        c = min(x.size(),y.size());
        for(long long int i=0;i<y.size();i++){
            if(c>0){
                ans1+=(2*y[i]);
                if(i!=(y.size()-1))
                    ans2+=(2*y[i]);
            }
            else{
                ans1+=(y[i]);
                if(i!=(y.size()-1))
                    ans2+=(y[i]);
            }
            c--;
        }
        cout<<max(ans1,ans2)<<endl;
    }
}