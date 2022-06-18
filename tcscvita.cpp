#include </Users/bits/stdc++.h>
using namespace std;

void display(vector <double> v){
    for(int i=0;i<(int)v.size();i++)
        cout << fixed << setprecision(6) << v[i] << " ";
    cout<<endl;
}

int main(){
    int x,y,n;
    cin>>x>>y;
    cin>>n;
    vector <double> v(n),a,b;
    for(int i=0;i<n;i++)
        cin>>v[i];
    queue <double> q1,q2;
    double s1=0.0,s2=0.0;
    for(int i=0;i<n;i++){
        if((int)q1.size()<x){
            q1.push(v[i]);
            s1+=v[i];
        }
        else{
            s1-=q1.front();
            q1.pop();
            q1.push(v[i]);
            s1+=v[i];
        }
        if((int)q2.size()<y){
            q2.push(v[i]);
            s2+=v[i];
        }
        else{
            s2-=q2.front();
            q2.pop();
            q2.push(v[i]);
            s2+=v[i];
        }
        if((int)q1.size()==x)
            a.push_back(s1/x);
        if((int)q2.size()==y)
            b.push_back(s2/y);
    }
    int c = 0,f=(a[a.size()-1]<b[b.size()-1])?0:1;
    for(int i=0;i<(int)b.size();i++){
        if(a[a.size()-i-1]<b[b.size()-i-1] && f==1){
            c++;
            f = 0;
        }
        else if(a[a.size()-i-1]>b[b.size()-i-1] && f==0){
            c++;
            f = 1;
        }
    }
    cout<<c<<endl;
}