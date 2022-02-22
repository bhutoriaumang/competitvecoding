#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        string s1,s2,s="";
        cin>>s1>>s2;
        vector <pair <int,int> > v1,v2;
        int i1=0,i2=0,t1=0,t2=0,tz;
        for(int i=0;i<n;i++){
            if(s1[i]=='1')
                break;
            s+='0';
            i1++;
        }
        for(int i=0;i<n;i++){
            if(s2[i]=='1')
                break;
            s+='0';
            i2++;
        }
        for(int i=i1;i<n;){
            int c1=0,c2=0;
            while(i<n && s1[i]=='1'){
                i++;
                c1++;
            }
            while(i<n && s1[i]=='0'){
                i++;
                c2++;
                t1++;
            }
            v1.push_back(make_pair(c1,c2));
        }
        for(int i=i2;i<n;){
            int c1=0,c2=0;
            while(i<n && s2[i]=='1'){
                i++;
                c1++;
            }
            while(i<n && s2[i]=='0'){
                i++;
                c2++;
                t2++;
            }
            v2.push_back(make_pair(c1,c2));
        }
        int k1=0,k2=0;
        tz = t1+t2;
        while(k1<v1.size() && k2<v2.size()){
            int x = v1[k1].first * v2[k2].second;
            int y = v2[k1].first * v1[k2].second;
            if(x>y || (x==y && t2>t1)){
                t2-=v2[k2].second;
                for(int j=0;j<(v2[k2].first+v2[k2].second);j++){
                    s+=s2[i2];
                    i2++;
                }
                k2++;
            }
            else{
                t1-=v1[k1].second;
                for(int j=0;j<(v1[k1].first+v1[k1].second);j++){
                    s+=s1[i1];
                    i1++;
                }
                k1++;
            }
        }
        while(i1<n){
            s+=s1[i1];
            i1++;
        }
        while(i2<n){
            s+=s2[i2];
            i2++;
        }
        long long int sum = 0,f=0;
        for(int i=0;i<2*n;i++){
            if(s[i]=='1'){
                sum+= tz;
                f=1;
            }
            else if(f)
                tz--;
        }
        cout<<sum<<endl;
    }
}