#include <bits/stdc++.h>
using namespace std;

int check(string s){
    vector <int> f(26,0);
    int n = s.length();
    for(int i=0;i<n-1;i++){
        if(f[(int)s[i] - 65]==1)
            return 0;
        f[(int)s[i] - 65] = 1;
        while(i<n-1 && s[i]==s[i+1]){
            i++;
        }
    }
    if(n>1 && s[n-1]!=s[n-2] && f[(int)s[n-1] - 65]==1)
        return 0;
    return 1;
}

string calcTwo(vector <string> v,int n,int tsize, string s){
    if(n==0){
        if(check(s)){
            return s;
        }
        return "IMPOSSIBLE";
    }
    vector <string> x(n);
    for(int i=0;i<v.size();i++){
        vector <string> t = v;
        t.erase(t.begin() + i);
        x[i]=calcTwo(t,t.size(),tsize,s+v[i]);
    }
    for(int i=0;i<n;i++){
        if(x[i]!="IMPOSSIBLE")
            return x[i];
    }
    return "IMPOSSIBLE";
}

int main(){
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        int n;
        cin>>n;
        int flag = 0;
        vector <string> v(n);
        vector <int> f(n,0);
        int tsize = 0;
        vector <string> temp;
        for(int i=0;i<n;i++){
            cin>>v[i];
            tsize+=v[i].length();
            if(v[i][0]==v[i][v[i].length()-1]){
                f[i] = 1;
                temp.push_back(v[i]);
            }
            if(!check(v[i]))
                flag = 1;
        }
        cout << "Case #" << cas << ": ";
        if(n<=6){
            cout<<calcTwo(v,n,tsize,"")<<"\n";
            continue;
        }
        if(flag){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        int ind = 0;
        while(ind<v.size()){
            if(f[ind]){
                v.erase(v.begin()+ind);
                f.erase(f.begin()+ind);
            }
            else
                ind++;
        }
        for(int i=0;i<temp.size();i++){
            int f = 0;
            for(int j=0;j<v.size();j++){
                if(v[j][0]==temp[i][0]){
                    v[j] = temp[i]+v[j];
                    f = 1;
                    break;
                }
                if(v[j][v[j].length()-1]==temp[i][0]){
                    v[j] += temp[i];
                    f = 1;
                    break;
                }
            }
            if(f){
                temp.erase(temp.begin()+i);
                i--;
            }
        }
        string ans = "";
        vector < pair <int,int> > x(26,make_pair(0,0));
        for(int i=0;i<v.size();i++){
            x[(int)v[i][0] - 65].first++;
            x[(int)v[i][v[i].length()-1] - 65].second++;
        }
        for(int i=0;i<x.size();i++){
            if(x[i].first>1 || x[i].second>1){
                flag = 1;
                break;
            }
        }
        if(flag){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        for(int i=0;i<v.size();i++){
            int k = -1;
            for(int j=0;j<v.size();j++){
                if(i==j)
                    continue;
                if(v[i][0]==v[j][v[j].length()-1]){
                    k = j;
                    break;
                }
            }
            if(k!=-1){
                v[i] = v[k] + v[i];
                v.erase(v.begin() + k);
            }
        }
        for(int i=0;i<v.size();i++)
            ans+=v[i];
        for(int i=0;i<temp.size();i++)
            ans+=temp[i];
        if(check(ans))
            cout<<ans<<"\n";
        else
            cout<<"IMPOSSIBLE\n";
    }
}