#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,x=0;
        cin>>n;
        vector <long long int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
            v[i]%=2;
            x+=v[i];
        }
        if(x==0){
            cout<<"-1\n";
            continue;
        }
        int k = 0,ans1=0,ans2=0,o1=-1,o2=-1;
        for(int i=0;i<n;i++){
            if(v[i]==k && k==1)
                o2 = i;
            else if(v[i]==1)
                o1 = i;
            k = 1-k;
        }
        k = 0;
        vector <pair <int,int> > x1,x2;
        for(int i=0;i<n;i++){
            if(v[i]==k)
                x1.push_back(make_pair(i,o1));
            else
                x2.push_back(make_pair(i,o2));
            k = 1-k;
        }
        if(x1.size()<x2.size())
            x2 = x1;
        cout<<x2.size()<<endl;
        for(int i=0;i<x2.size();i++)
            cout<<(x2[i].first+1)<<" "<<(x2[i].second+1)<<endl;
    }
}