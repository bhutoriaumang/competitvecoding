#include <iostream>
#include <map>
#include <iterator>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int cas = 1;cas<=t;cas++){
        int n;
        cin>>n;
        long long int a[n],d[n-1];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<n-1;i++)
            d[i] = (long long int)(a[i]-a[i+1]);
        long long int f = 0,c=0,max = 0,ff=0,diff = -1;
        for(int i=0;i<n-1;i++){
            if(ff==0 || (a[i]-a[i+1])==diff){
                ff = 1;
                c++;
                diff = a[i]-a[i+1];
            }
            else{
                if(f==0){
                    if(c!=0){
                        a[i+1] = a[i]-diff;
                    }
                    diff = a[i]-a[i+1];
                    c++;
                    f = 1;
                }
                else{
                    if(c>max)
                        max = c;
                    c = 0;
                    f = 0;
                }
            }
        }
        if(c>max)
            max = c;
        cout<<"Case #"<<cas<<": "<<max+1<<"\n";
    }
}