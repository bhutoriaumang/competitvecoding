#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        const int A = 1e9 + 1;
        int minl=A,cl=A,maxr=0,cr=A,maxlen=0,clen=A;
        for(int i=0;i<n;i++){
            int l,r,c;
            cin>>l>>r>>c;
            if(l<minl)
                minl=l,cl=A;
            if(l==minl)
                cl=min(cl,c);
            
            if(maxr<r)
                maxr=r,cr=A;
            if(r==maxr)
                cr=min(cr,c);
            
            if(maxlen<(r-l+1))
                maxlen=r-l+1,clen=A;
            if(maxlen==(r-l+1))
                clen=min(clen,c);
            
            int ans = cl+cr;
            if(maxlen==(maxr-minl+1))
                ans = min(ans,clen);
            cout<<ans<<"\n";
        }
    }
}