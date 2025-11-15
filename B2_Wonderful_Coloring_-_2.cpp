/*

Problem Tags: ['binary search', 'constructive algorithms', 'data structures', 'greedy'] 

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,k;
        cin>>n>>k;
        int a[n],x[n+1],f[n+1],y[n+1];
        vector <int> v;
        for(int i=0;i<n;i++){
            cin>>a[i];
            f[a[i]] = 0;
            v.push_back(a[i]);
        }
        sort(v.begin(),v.end());
        if(n==1){
            cout<<"1"<<endl;
            continue;
        }
        int s = 0,an=0;
        for(int i =0;i<v.size()-1;i++){
            int co = 1;
            while(i<(n-1) && v[i]==v[i+1]){
                co++;
                i++;
            }
            f[v[i]] = 0;
            if(co>=k){
                f[v[i]] = 1;
                y[v[i]] = k;
                x[v[i]] = co;
                an++;
            }
            else{
                x[v[i]] = s%k;
                y[v[i]] = (s+co)%k;
                s+=co;
            }
        }
        if(v[n-1]!=v[n-2]){
            f[v[n-1]] = 0;
            x[v[n-1]] = s%k;
            s++;
            y[v[n-1]] = s%k;
        }
        an+=(s/k);
        vector <int> ans;
        vector <int> anss(k+1,an);
        for(int i=0;i<n;i++){
            if(f[a[i]]==1){
                if(y[a[i]]>0){
                    if(anss[y[a[i]]]>0)
                        ans.push_back(y[a[i]]);
                    else
                        ans.push_back(0);
                    anss[y[a[i]]]--;
                    y[a[i]]--;
                }
                else{
                    ans.push_back(0);
                }
            }
            else{
                if(anss[x[a[i]]+1]>0)
                    ans.push_back(x[a[i]]+1);
                else
                    ans.push_back(0);
                x[a[i]]++;
                anss[x[a[i]]]--;
                x[a[i]]=x[a[i]]%(k);
            }
        }
        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<endl;
    }
}