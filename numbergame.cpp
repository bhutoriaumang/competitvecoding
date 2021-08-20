#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    double phi = (1+sqrt(5.0))/2.0;
    for(int cas=1;cas<=t;cas++){
        double a1,a2,b1,b2;
        cin>>a1>>a2>>b1>>b2;
        int ans = 0;
        for(int b=b1;b<=b2;b++){
            if(a1 > floor(b*phi) || floor((phi-1)*b) >a2)
                ans+= a2-a1+1;
            else{
                ans+=max(0.0,a2-floor(b*phi));
                ans+=max(0.0, floor(b*(phi-1)) - a1 + 1);
            }
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;;
    }
}