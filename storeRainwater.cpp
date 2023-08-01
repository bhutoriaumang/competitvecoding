#include <bits/stdc++.h>
using namespace std;

int calc(vector <int> v,int i,int j){
    // cout<<i<<" "<<j<<endl;
    if(j<=(i+1))
        return 0;
    stack <int> s;
    for(int k=i;k<=j;k++){
        if(s.empty())
            s.push(k);
        else{
            if(v[s.top()]<=v[k])
                s.push(k);
        }
    }
    int k2 = s.top();
    if(s.size()<2)
        return calc(v,k2+1,j);
    s.pop();
    int k1 = s.top();
    // cout<<"HI\n";
    int sum=0;
    for(int k=k1+1;k<k2;k++)
        sum+=v[k];
    // cout<<i<<" "<<k1<<" "<<k2<<" "<<j<<endl;
    return calc(v,i,k1)+calc(v,k2,j)+((k2-k1-1)*min(v[k1],v[k2])-sum);

}

int main(){
    int n;
    cin>>n;
    vector <int> v(n);
    for(int i=0;i<n;i++)
        cin>>v[i];
    cout<<calc(v,0,n-1);
}