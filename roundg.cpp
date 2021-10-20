#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int cas = 1;cas<=T;cas++){
        int n,k;
        cin>>n>>k;
        vector <int> x(n);
        vector <long long int> s;
        long long int sum = 0;
        queue <long long int> q;
        for(int i=0;i<n;i++){
            cin>>x[i];
            sum+=x[i];
            s.push_back(sum);
            q.push(sum);
        }
        for(int i=0;i<n;i++){
            int l = q.size();
            int f = 0;
            while(l-->0){
                long long int t = q.front();
                q.pop();
                t-=x[i];
                if(f){
                    q.push(t);
                }
                f = 1;
            }
            l = q.size();
            while(l-->0){
                s.push_back(q.front());
                q.pop();
                q.push(s.back());
            }
        }
        vector <int> v(1000001,-1),c(1000001,0),bv(1000001,-1);
        sum = 0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=n-i;j++){
                if(s[sum]>k){
                    sum++;
                    continue;
                }
                if(c[s[sum]]>=1){
                    // cout<<j<<"\t"<<s[sum]<<"\t"<<bv[s[sum]]<<endl;
                    bv[s[sum]] = (bv[s[sum]]==-1)?max(j,v[s[sum]]):min(max(j,v[s[sum]]),bv[s[sum]]);
                    // cout<<j<<"\t"<<s[sum]<<"\t"<<bv[s[sum]]<<endl;
                }
                v[s[sum]] = (v[s[sum]]==-1)?j:min(j,v[s[sum]]);
                c[s[sum]]++;
                sum++;
            }
        }
        int ans = -1;
        v[0] = 0;
        for(int i=0;i<=k;i++){
            if(v[i]!=-1 && v[k-i]!=-1){
                if(i==(k-i) && c[i]<=1)
                    continue;
                // cout<<i<<" "<<(k-i)<<"\t"<<v[i]<<"\t"<<v[k-i]<<"\t"<<bv[i]<<"\t"<<ans<<endl;
                if(i!=(k-i))
                    ans = (ans==-1)?(v[i]+v[k-i]):min(ans,v[i]+v[k-i]);
                else
                    ans = (ans==-1)?(v[i]+v[k-i]):min(ans,v[i]+bv[i]);
            }
        }
        cout<<"Case #"<<cas<<": "<<ans<<endl;
    }
}