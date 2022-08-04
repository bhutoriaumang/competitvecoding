#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <long long int> v(n),a;
        set <long long int> x;
        int c1=0,c2=0,c3=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]!=0)
                a.push_back(v[i]);
            if(v[i]>0)
                c1++;
            else if(v[i]<0)
                c2++;
            else
                c3++;
        }
        sort(a.begin(),a.end());
        if(c1==0 && c2==0)
            cout<<"YES\n";
        else if(c1>2 || c2>2 || c1==0 || c2==0)
            cout<<"NO\n";
        else if(c3==0 && c1==2 && c2==2){
            if(a[0]==(-a[3]) && a[1]==(-a[2]))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else if(c3==0 && n==3){
            long long int s = v[0]+v[1]+v[2];
            if(s==v[0] || s==v[1] || s==v[2])
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else if(c1==1 && c2==1){
            if(a[0]==(-a[1]))
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else
            cout<<"NO\n";
    }
}