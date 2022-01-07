#include <bits/stdc++.h>
using namespace std;

int minchanges(vector <int> v,double x,double y){
    int n = v.size()-1;
    int a = n-1,b=1,count=0;
    if(v[0]!=x)
        count++;
    if(v[n]!=y)
        count++;
    for(int i=1;i<n;i++){
        double d = (double)(a*x + b*y)/(double)n;
        if(d!=v[i])
            count++;
        a--;
        b++;
    }
    a = n-1,b=1;
    return count;
}

int buildarr(vector <int> v,int a,int b){
    double x,y;
    int n = v.size()-1;
    int a1 = n-a;
    int b1 = a;
    int a2 = n-b;
    int b2 =b;
    int c1 = v[a]*n;
    int c2 = v[b]*n;
    y = (double)(a2*c1 - c2*a1)/(double)(b2*a1 - b1*a2);
    x = (double)(c1 - b1*y)/(double)(a1);
    if(a==0){
        x = v[0];
        y = (double)(c1 - a1*x)/(double)(b1);
    }
    if(b==n){
        y = v[n];
        x = (double)(c1 - b1*y)/(double)(a1);
    }
    int count = minchanges(v,x,y);
    return count;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        int m = n-1;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++)
                m = min(m,buildarr(v,i,j));
        }
        cout<<m<<endl;
    }
}