#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        int n;
        cin>>n;
        vector <int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        sort(v.begin(),v.end());
        int k = 0;
        for(int i=0;i<n;i++){
            if((k+1)>v[i])
                continue;
            k++;
        }
        cout << "Case #" << cas << ": " << k<<endl;
    }
}