#include <bits/stdc++.h>
using namespace std;

vector <long long int> conv(long long int x){
    vector <long long int> v;
    int c=0;
    while(x>0){
        if(x%2==1)
            v.push_back(pow(2,c));
        c++;
        x/=2;
    }
    reverse(v.begin(),v.end());
    return v;
}

int countBits(long long int x){
    int c = 0;
    while(x>0){
        x/=2;
        c++;
    }
    return c;
}

int main(){
    int T;
    cin>>T;
    // cout<<countBits(1e9)<<endl;
    while(T-->0){
        long long int n,k;
        cin>>n>>k;
        vector <long long int> v = conv(k);
        long long int count = v.size();
        long long int i = 0;
        while(v.size()<n){
            if(i==v.size() || v[i]==1)
                break;
            v[i]-=1;
            count+=countBits(v[i]);
            v.push_back(1);
            i++;
        }
        count = max(count,(long long int)min(n,k));
        cout<<count<<endl;
    }
}