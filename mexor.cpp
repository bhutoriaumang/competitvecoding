#include </Users/bits/stdc++.h>
using namespace std;

bool isAPowerof2(long long int x){
    return (ceil(log2(x))==floor(log2(x)));
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int x;
        cin>>x;
        if(x==0){
            cout<<"1\n";
        }
        else if(x==1){
            cout<<"2\n";
        }
        else if(isAPowerof2(x)){
            cout<<x<<"\n";
        }
        else if(isAPowerof2(x+1)){
            cout<<x+1<<"\n";
        }
        else{
            long long int c = 0;
            while(x>0){
                if(!c)
                    c = 1;
                else
                    c*=2;
                x/=2;
            }
            cout<<c<<endl;
        }
    }
}