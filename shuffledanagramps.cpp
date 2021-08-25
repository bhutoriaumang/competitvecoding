#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    for(int cas = 1;cas<=T;cas++){
        string s,w;
        cin>>s;
        w = s;
        int n = s.length();
        sort(s.begin(),s.end());
        vector <pair<int,char> > v;
        for(int i=0;i<n-1;i++){
            int c = 1;
            while(i<n && s[i]==s[i+1]){
                i++;
                c++;
            }
            v.push_back(make_pair(c,s[i]));
        }
        if(s[n-1]!=s[n-2])
            v.push_back(make_pair(1,s[n-1]));
        sort(v.begin(),v.end());
        reverse(v.begin(),v.end());
        map <char,vector <char> > m;
        while(true){
            for(int i=0;i<v.size();i++)
                cout<<v[i].first<<" "<<v[i].second<<"\t";
            cout<<endl;
            int i=0;
            if(v[i].first==0)
                break;
            int s = 0,j=i+1;
            while(s!=v[i].first){
                if(v[j].first > (v[i].first - s)){
                    v[j].first -= (v[i].first-s);
                    s = v[i].first;
                    break;
                }
                s+=v[j].first;
                v[j].first=0;
                if(s==v[i].first)
                    break;
                j++;
            }
            v[i].first = 0;
            cout<<i<<j<<"\n";
            for(int k=i+1;k<=j;k++){
                m[v[k].second].push_back(v[i].second);
                m[v[i].second].push_back(v[k].second);
            }
            sort(v.begin(),v.end());
            reverse(v.begin(),v.end());
        }
        for(auto it=m.begin();it!=m.end();it++){
            cout<<it->first<<"\t:\t";
            for(int j=0;j<it->second.size();j++)
                cout<<it->second[j]<<"\t";
            cout<<endl;
        }
    }
}