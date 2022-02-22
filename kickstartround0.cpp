#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int cas = 1;cas<=T;cas++){
        int n;
        cin>>n;
        vector <int> v(n),x,a(100001,0),t;
        for(int i=0;i<n;i++)
            cin>>v[i];
        x = v;
        sort(x.begin(),x.end());
        int c = 0;
        for(int i=0;i<n-1;i++){
            a[x[i]] = n-c;
            t.push_back(x[i]);
            c++;
            while(i<(n-1) && x[i]==x[i+1]){
                i++;
                c++;
            }
        }
        if(n>1 && x[n-1]!=x[n-2]){
            t.push_back(x[n-1]);
            a[x[n-1]] = 1;
        }
        int k = 0;
        for(int i=0;i<a.size();i++){
            if(a[i]==0)
                continue;
            cout<<t[k++]<<" : "<<i<<" "<<a[i]<<endl;
        }
    }
}