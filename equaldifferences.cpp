#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <long long int> v(n);
        for(auto &i : v)
            cin>>i;
        sort(v.begin(),v.end());
        if(n<=2){
            cout<<"0\n";
            continue;
        }
        long long int maximum = 2;
        for(int i=0;i<n-1;i++){
            long long int c = 1;
            while(i<n && v[i]==v[i+1]){
                i++;
                c++;
            }
            maximum = max(maximum,c);
        }
        cout<<(n-maximum)<<"\n";
    }
}