#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,c,q;
        cin>>n>>c>>q;
        string s;
        cin>>s;
        vector <string> v;
        v.push_back(s);
        for(int x=0;x<c;x++){
            long long int l,r;
            cin>>l>>r;
            string w = "";
            int size = r-l+1;
            for(int i=0;i<v.size();i++){
                if((l-(long long int)v[i].length())>0){
                    l-=(long long int)v[i].length();
                    continue;
                }
                int j=0;
                while(l>1){
                    l--;
                    j++;
                }
                while(size>0 && j<(long long int)v[i].length()){
                    size--;
                    w+=v[i][j++];
                }
            }
            v.push_back(w);
        }
        // for(int i=0;i<v.size();i++)
        //     cout<<v[i]<<endl;
        for(int x=0;x<q;x++){
            long long int k;
            cin>>k;
            for(int i=0;i<v.size();i++){
                if((k-(long long int)v[i].length())>0){
                    k-=(long long int)v[i].length();
                    continue;
                }
                int l = 0,t=0;
                char c;
                for(int j=0;j<(long long int)v[i].length();j++){
                    c = v[i][j];
                    k--;
                    if(k==0)
                        break;
                }
                if(k==0)
                    cout<<c<<endl;
            }
        }
    }
}