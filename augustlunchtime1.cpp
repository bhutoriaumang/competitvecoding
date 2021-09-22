#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,k;
        cin>>n>>k;
        vector <int> a(n);
        for(auto &i : a)
            cin>>i;
        vector <int> m(1,0);
        for(int i=0;i<n;i++){
            if(a[m[0]]<a[i]){
                m.clear();
                m.push_back(i);
            }
            else if(a[m[0]]==a[i])
                m.push_back(i);
        }
        int c = n-m[m.size()-1];
        for(int i=0;i<m.size()-1;i++){
            int t = m[i];
            if(t>=(k-1)){
                c+= (m[i+1]-t);
            }
        }
        cout<<c<<endl;
    }
}