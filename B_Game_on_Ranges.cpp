#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector < vector <int> > v(n);
        queue < vector <int> > x;
        for(int i=0;i<n;i++){
            int a,b;
            cin>>a>>b;
            v[i].push_back(b-a);
            v[i].push_back(a);
            v[i].push_back(b);
        }
        int m = 0,k=0;
        sort(v.begin(),v.end());
        vector <pair<int,int> > ans;
        for(int i=0;i<=n;i++)
            ans.push_back(make_pair(i,0));
        // cout<<"HI\n";
        while(m!=n){
            // cout<<"HI\n";
            while(k<n && v[k][0]==m){
                vector <int> temp;
                temp.push_back(v[k][0]);
                temp.push_back(v[k][1]);
                temp.push_back(v[k][2]);
                x.push(temp);
                k++;
            }
            // cout<<"HII\n";
            while(x.size()!=0){
                int a=-1,b=-1;
                for(int i=x.front()[1];i<=x.front()[2];i++){
                    if(ans[i].second==0){
                        a = i;
                        break;
                    }
                }
                for(int i=x.front()[2];i>=x.front()[1];i--){
                    if(ans[i].second==0){
                        b = i;
                        break;
                    }
                }
                // cout<<a<<" "<<b<<endl;
                if(a==b && a!=-1){
                    cout<<x.front()[1]<<" "<<x.front()[2]<<" "<<a<<endl;
                    ans[a].second = 1;
                }
                else
                    x.push(x.front());
                x.pop();
            }
            // cout<<"HIII\n";
            m++;
        }
        cout<<endl;
    }
}