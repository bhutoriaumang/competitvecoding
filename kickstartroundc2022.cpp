#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        cout<<"Case #"<<cas<<": ";
        long long int n,x,y;
        cin>>n>>x>>y;
        long long int s = (n*(n+1))/2,d;
        if(s%(x+y)!=0){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        cout<<"POSSIBLE\n";
        d = x*(s/(x+y));
        vector <int> v(n),alan;
        for(int i=n;i>0;i--){
            if(d==0)
                break;
            if(d>=i){
                alan.push_back(i);
                d-=i;
            }
        }
        sort(alan.begin(),alan.end());
        cout<<alan.size()<<endl;
        for(int i=0;i<alan.size();i++){
            cout<<alan[i]<<" ";
        }
        cout<<endl;
    }
}