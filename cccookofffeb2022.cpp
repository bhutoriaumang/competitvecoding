#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        string s;
        cin>>s;
        if(s[n]=='0' || s[0]=='0' || s[1]=='0'){
            cout<<"NO\n";
            continue;
        }
        stack <int> ans;
        int f = 1;
        for(int i=0;i<n;i++){
            if(s[i]=='1')
                ans.push(i);
            else{
                if(ans.size()==0){
                    f = 0;
                    break;
                }
                int x = ans.top();
                ans.pop();
                ans.push(i);
                ans.push(x);
            }
        }
        if(f==0)
            cout<<"NO\n";
        else{
            vector <int> v(n);
            int k = n-1;
            cout<<"YES\n";
            while(!ans.empty()){
                v[k--] = ans.top();
                ans.pop();
            }
            for(int i=0;i<n;i++)
                cout<<v[i]<<" ";
            cout<<"\n";
        }
    }
}