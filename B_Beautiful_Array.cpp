#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int n,k,b,s;
        cin>>n>>k>>b>>s;
        long long int x = s/k,xx=s - ((n-1)*(k-1));
        if(b>x || b<(xx/k)){
            cout<<"-1\n";
            continue;
        }
        long long int y = b*k + min(s-(b*k),(k-1));
        long long int z = (s-y)/(k-1);
        vector <long long int> ans;
        ans.push_back(y);
        s-=y;
        while(s>0){
            ans.push_back(min(k-1,s));
            s = max((long long int)0,s-k+1);
        }
        for(int i=0;i<n;i++){
            if(i<ans.size())
                cout<<ans[i]<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
}