/*

Problem Tags: ['greedy', 'sortings', 'strings'] 

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n;
        cin>>n;
        vector <long long int> a;
        vector <long long int> b;
        vector <long long int> c;
        vector <long long int> d;
        vector <long long int> e;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            vector <int> x(5,-s.length());
            for(int i=0;i<s.length();i++){
                x[(int)(s[i]) - 97]+=2;
            }
            a.push_back(x[0]);
            b.push_back(x[1]);
            c.push_back(x[2]);
            d.push_back(x[3]);
            e.push_back(x[4]);
        }
        sort(a.begin(),a.end(),greater<long long int>());
        sort(b.begin(),b.end(),greater<long long int>());
        sort(c.begin(),c.end(),greater<long long int>());
        sort(d.begin(),d.end(),greater<long long int>());
        sort(e.begin(),e.end(),greater<long long int>());
        int co = 0;
        int sa=a[0],sb=b[0],sc=c[0],sd=d[0],se=e[0];
        while(sa>0 || sb>0 || sc>0 || sd>0 || se>0){
            co++;
            if(co==n)
                break;
            sa+=a[co];
            sb+=b[co];
            sc+=c[co];
            sd+=d[co];
            se+=e[co];
        }
        cout<<co<<endl;
    }
}