#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,h,m;
        cin>>n>>h>>m;
        vector < pair <int,int> > v(n);
        for(int i=0;i<n;i++)
            cin>>v[i].first>>v[i].second;
        sort(v.begin(),v.end());
        int ansh = 0,ansm=0;
        int f=0;
        for(int i=0;i<n;i++){
            if(v[i].first<h)
                continue;
            else if(v[i].first==h && v[i].second<m)
                continue;
            else if(v[i].first>=h){
                f=1;
                ansh = v[i].first-h;
                if(m>v[i].second){
                    ansm = (60-m)+v[i].second;
                    ansh--;
                }
                else
                    ansm = v[i].second-m;
                break;
            }
        }
        if(!f){
            ansh = 24-h-1;
            ansm = 60-m;
            ansh+=(ansm/60);
            ansm%=60;
            ansh+=v[0].first;
            ansm+=v[0].second;
            ansh+=(ansm/60);
            ansm%=60;
        }
        cout<<ansh<<" "<<ansm<<endl;
    }
}