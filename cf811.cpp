#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        string t;
        cin>>t>>n;
        vector <string> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        vector < pair <int,int> > x;
        for(int i=0;i<n;i++){
            for(int j=0;j<t.length();j++){
                if(t.substr(j,v[i].length())==v[i])
                    x.push_back(make_pair(j,i));
            }
        }
        sort(x.begin(),x.end());
        int d=0;
        vector < pair <int,int> > ans;
        for(int i=0;i<x.size();i++){
            int dd = i;
            int flag = 0;
            while(i<x.size() && x[i].first<=d && x[i].first+v[x[i].second].length()-1>=d){
                if(x[i].first+v[x[i].second].length()-1>x[dd].first+v[x[dd].second].length()-1)
                    dd = i;
                i++;
                flag=1;
            }
            d = x[dd].first+v[x[dd].second].length()-1+1;
            if(flag)
                i--;
            ans.push_back(make_pair(x[dd].first+1,x[dd].second+1));
            if(d==t.length())
                break;
        }
        if(ans.size()==0 || d!=t.length()){
            cout<<"-1"<<endl;
            continue;
        }
        cout<<ans.size()<<endl;
        for(int i=0;i<ans.size();i++)
            cout<<ans[i].second<<" "<<ans[i].first<<endl;
    }
}