#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int k=0;
        set <int> v;
        char a[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                a[i][j] = '!';
        }
        for(int i=0;i<n;i++){
            if(s[i]=='2')
                k++;
            for(int j=0;j<n;j++){
                if(a[i][j]!='!')
                    continue;
                if(i==j)
                    a[i][j] = 'X';
                else if(s[i]=='1' && s[j]=='1')
                    a[i][j] = '=';
                else if(s[i]=='1'){
                    a[i][j] = '+';
                    a[j][i] = '-';
                }
                else if(s[j]=='1'){
                    a[i][j] = '-';
                    a[j][i] = '+';
                }
                else{
                    a[i][j] = '.';
                    if(s[i]=='2')
                        v.insert(i);
                    if(s[j]=='2')
                        v.insert(j);
                }
            }
        }
        if(k<=2 && k>0)
            cout<<"NO\n";
        else{
            cout<<"YES\n";
            vector <int> t;
            for(auto it = v.begin();it!=v.end();it++){
                t.push_back(*it);
            }
            sort(t.begin(),t.end());
            for(int i=0;i<k-1;i++){
                a[t[i]][t[i+1]] = '+';
                a[t[i+1]][t[i]] = '-';
            }
            if(k>0){
                a[t[t.size()-1]][t[0]] = '+';
                a[t[0]][t[t.size()-1]] = '-';
            }
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(a[i][j]=='.')
                        a[i][j]='=';
                    cout<<a[i][j];
                }
                cout<<endl;
            }
        }
    }
}