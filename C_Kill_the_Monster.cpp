#include <bits/stdc++.h>
using namespace std;

bool surviving(long long int a,long long int b,long long int c,long long int d){
    long long int x = ceil((double)a/(double)d);
    long long int y = ceil((double)c/(double)b);
    return (x>=y);
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int hc,dc,hm,dm,k,w,a;
        cin>>hc>>dc>>hm>>dm;
        cin>>k>>w>>a;
        if(surviving(hc,dc,hm,dm)){
            cout<<"YES\n";
        }
        else{
            int f = 0;
            for(int i=0;i<=k;i++){
                long long int x = i*w;
                long long int y = (k-i)*a;
                if(surviving(hc+y,dc+x,hm,dm)){
                    f = 1;
                    break;
                }
            }
            if(f)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}