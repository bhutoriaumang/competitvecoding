#include </Users/bits/stdc++.h>
using namespace std;

int cal(vector<string> v,string s){
    vector <pair<string,string> > x;
    vector <int> t(0,v.size());
    for(int i=0;i<v.size();i++)
        x.push_back(make_pair(v[i],s));
    for(int i=0;i<s.length();i++){
        for(int j =0;j<v.size();j++){
            if(x[j].first.compare(v[j])==0 && x[j].second[0]=='0'){
                t[j]++;
                continue;
            }
            if(x[j].first[0]==x[j].second[0]){
                x[j].first = (x[j].first.length()!=1)?x[j].first.substr(1):"";
            }
            x[j].second = x[j].second.substr(1);
            if(x[j].first.length()==0)
                return i-t[j];
        }
    }
    int m = s.length() + 2*(x[0].first.length()) - v[0].length();
    for(int i=1;i<v.size();i++){
        m = min( m , (int)(s.length() + 2*(x[i].first.length()) - v[i].length()) );
    }
    return m;
}

int main(){
    vector <string> v;
    long long int k = 1;
    while(k<=1000000000){
        v.push_back(to_string(k));
        k*=2;
    }
    int t;
    cin>>t;
    while(t-->0){
        string s;
        cin>>s;
        
        cout<<"\nANS : \n"<<cal(v,s)<<"\n";
    }
}
