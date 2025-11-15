/*

Problem Tags: ['binary search'] 

*/

#include <bits/stdc++.h>
using namespace std;

long long int x1,x2,yy1,y2;

pair < long long int , long long int > count(string s,long long int i){
    pair <long long int , long long int> v;
    v.first = 0;
    v.second = 0;
    while(i>=0){
        if(s[i]=='U')
            v.second++;
        else if(s[i]=='R')
            v.first++;
        else if(s[i]=='D')
            v.second--;
        else if(s[i]=='L')
            v.first--;
        i--;
    }
    return v;
}

bool possible(string s, long long int d, pair <long long int,long long int> sum){
    pair <long long int , long long int> v = count(s,d%s.length() - 1);
    // cout<<d<<"\t"<<v.first<<"\tafno\t"<<v.second<<endl;
    v.first+= sum.first * (d/s.length());
    v.second+= sum.second * (d/s.length());
    long long int x = v.first + x1;
    long long int y = v.second + yy1;
    // cout<<x<<" : "<<x2<<"\t"<<y<<" : "<<y2<<"\t\n";
    return (abs(x-x2)+abs(y-y2))<=d;
}

int main(){
    cin>>x1>>yy1>>x2>>y2;
    long long int n;
    string s;
    cin>>n>>s;
    pair <long long int , long long int> sum = count(s,n-1);
    long long int l=0,u=1000000000000000;
    while(l<u){
        long long m = (l+u)/2;
        if(m==l || m==u)
            break;
        // cout<<l<<"\t adnml \t"<<m<<"\toiafin\t"<<u<<endl;
        if(possible(s,m,sum))
            u = m;
        else
            l = m;
    }
    // cout<<"qefnoenon\n\n\n";
    long long int m = (l+u)/2;
    l = possible(s,l,sum)?l:possible(s,m,sum)?m:possible(s,u,sum)?u:-1;
    cout<<l<<endl;
}