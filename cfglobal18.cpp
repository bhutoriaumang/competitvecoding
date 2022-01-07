#include </Users/bits/stdc++.h>
using namespace std;

int count(int x){
    int c = 0;
    while(x>0){
        c++;
        x/=2;
    }
    return c;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int l,r;
        cin>>l>>r;
        int n = r-l+1;
        int c1=count(l),c2=count(r);
        vector <int> x(c2-c1+1,0);
        for(int i=pow(2,c2-1);i<=r;i++){
            int t = i,k=0;
            while(t>0){
                if(k==(c1-1))
                    x[k] += (t%2);
                t/=2;
                k++;
            }
        }
        for(int i=0;i<x.size();i++)
            cout<<x[i]<<" ";
        cout<<endl;
        for(int i=l;i<pow(2,c1);i++){
            int t = i,k=0;
            while(t>1){
                x[k++] += (t%2);
                t/=2;
            }
        }
        for(int i=0;i<x.size();i++)
            cout<<x[i]<<" ";
        cout<<endl;
        for(int i=c1+1;i<c2;i++){
            x[i-c1] = pow(2,i) - pow(2,i-1);
        }
        for(int i=0;i<x.size();i++)
            cout<<x[i]<<" ";
        cout<<endl;
        for(int i=c1+1;i<c2;i++){
            for(int j=0;j<(i-c1);j++){
                x[j] += x[i-c1]/2;
            }
        }
        for(int i=0;i<x.size();i++)
            cout<<x[i]<<" ";
        cout<<endl;
        int m = n-x[0];
        for(int i=0;i<x.size();i++)
            m = min(m,n-x[i]);
        cout<<m<<endl;
    }
}
// 0001
// 0010
// 0011
// 0100
// 0101
// 0110
// 0111
// 1000
// 1001
// 1010