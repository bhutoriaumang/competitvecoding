#include <bits/stdc++.h>
using namespace std;

int count(long long int x){
    int c = 0;
    while(x>0){
        x/=10;
        c++;
    }
    return c;
}

int check(long long int x, long long int y){
    string a = to_string(x);
    string b = to_string(y);
    for(int i=0;i<a.length();i++){
        if(a[i]==b[i])
            continue;
        return i+1;
    }
    return a.length();
}

int main(){
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        long long int n;
        cin>>n;
        vector <long long int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        long long int ans = 0;
        for(int i=1;i<n;i++){
            if(v[i]>v[i-1])
                continue;
            long long int x = count(v[i]);
            long long int y = count(v[i-1]);
            if(x==y){
                ans++;
                v[i]*=10;
                continue;
            }
            if(to_string(stoll(to_string(v[i-1]).substr(x)) + 1).length() != to_string(v[i-1]).substr(x).length() && to_string(stoll(to_string(v[i-1]).substr(x))).length()==to_string(v[i-1]).substr(x).length()){
                cout << "A\n";
                v[i] *= pow(10,y-x+1);
                ans += (y-x+1);
            }
            else{
                cout << "B\n";
                ans+=(y-x);
                v[i] = stoll(to_string(v[i]) + to_string(v[i-1]).substr(x));
                if(v[i]==v[i-1])
                    v[i]+=1;
                else if(v[i]<v[i-1]+1){
                    ans++;
                    v[i]*=10;
                }
            }
            cout<<v[i]<<endl;
        }
        cout << "Case #" << cas << ": " << ans << endl;
    }
}

1999999999
5000 0000000