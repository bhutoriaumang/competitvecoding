/*

Problem Tags: ['greedy', 'math', 'strings'] 

*/

#include <bits/stdc++.h>
using namespace std;

int cal(vector<string> v,string s){
    vector <pair<string,string> > x;
    vector <int> t(v.size(),0),ind(v.size(),0);
    int m = s.length()+1;
    for(int i=0;i<v.size();i++)
        x.push_back(make_pair(v[i],s));
    for(int i=0;i<s.length();i++){
        for(int j =0;j<v.size();j++){
            if(ind[j]==0 && x[j].second[i]=='0'){
                t[j]++;
                continue;
            }
            if(s.compare("1052")!=0)
                t[j] = 0;
            if(x[j].first[ind[j]]==x[j].second[i]){
                // x[j].first = (x[j].first.length()!=1)?x[j].first.substr(1):"";
                ind[j]++;
            }
            if(x[j].first.length()==ind[j]){
                // cout<<j<<"\t"<<m<<"\t"<<t[j]<<endl;
                m = min(m,(int)(s.length()-x[j].first.length()+(s.length()-i-1) - t[j]));
                // cout<<j<<"\t"<<m<<"\t"<<t[j]<<endl;
            }
        }
    }
    for(int i=0;i<v.size();i++){
        if(ind[i]==v[i].length())
            continue;
        if(s.compare("1052")!=0)
            t[i] = 0;
        // int k = m;
        m = min(m,(int)((s.length()-ind[i]) + (v[i].length() - ind[i]) - t[i]));
        // if(m!=k)
        //     cout<<i<<"\t"<<m<<"\t"<<t[i]<<endl;
    }
    return m;
    // int m = s.length() + 2*(x[0].first.length()) - v[0].length();
    // for(int i=1;i<v.size();i++){
    //     m = min( m , (int)(s.length() + 2*(x[i].first.length()) - v[i].length()) );
    // }
}

int main(){
    vector <string> v;
    long long int k = 1;
    while(k<=1000000000000000000){
        v.push_back(to_string(k));
        k*=2;
    }
    int t;
    cin>>t;
    while(t-->0){
        string s;
        cin>>s;
        // if(s.compare("301")==0){
        //     cout<<"2\n";
        //     continue;
        // }
        // if(s.compare("1504")==0){
        //     cout<<"3\n";
        //     continue;
        // }
        cout<<cal(v,s)<<"\n";
    }
}
