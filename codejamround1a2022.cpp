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
        vector <string> v(n);
        int tsize = 0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            tsize+=v[i].length();
        }
        cout << "Case #" << cas << ": "<<calcTwo(v,n,tsize,"")<<" : ";
        while(true){
            int f = 0,k=-1;
            for(int i=0;i<v.size()-1;i++){
                for(int j=i+1;j<v.size();j++){
                    if(v[i][v[i].length()-1]==v[j][0]){
                        k = j;
                        break;
                    }
                }
                if(k!=-1){
                    v[i]+=v[k];
                    i--;
                    v.erase(v.begin()+k);
                    k = -1;
                    f = 1;
                }
            }
            reverse(v.begin(),v.end());
            k = -1;
            for(int i=0;i<v.size()-1;i++){
                for(int j=i+1;j<v.size();j++){
                    if(v[i][v[i].length()-1]==v[j][0]){
                        k = j;
                        break;
                    }
                }
                if(k!=-1){
                    v[i]+=v[k];
                    i--;
                    v.erase(v.begin()+k);
                    k = -1;
                    f = 1;
                }
            }
            if(f==0)
                break;
        }
        string s = "";
        for(int i=0;i<v.size();i++)
            s+=v[i];
        if(check(s))
            cout<<s<<"\n";
        else
            cout<<"IMPOSSIBLE\n";
    }
}