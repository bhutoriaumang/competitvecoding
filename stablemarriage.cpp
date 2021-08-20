#include </Users/bits/stdc++.h>
using namespace std;

// int cal(map < int , vector < pair <int,int> > > m , map < int , vector < pair <int,int> > > w , vector <int> mf , vector <int> wf , int x){
//     int n = m.size();
//     for(int i=0;i<n;i++){
//         if(wf[m[x]->second[i]].first==0)
//             return wf[m[x]->second[i]];
//     }
// }

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        map <int,vector<pair <int,int> > > m,w;
        vector <int> mf(0,n+1),wf(0,n+1);
        for(int i=0;i<n;i++){
            int t,k;
            cin>>t;
            for(int j=0;j<n;j++){
                cin>>k;
                w[t].push_back(make_pair(k,j+1));
            }
            sort(w[t].begin(),w[t].end());
        }
        for(int i=0;i<n;i++){
            int t,k;
            cin>>t;
            for(int j=0;j<n;j++){
                cin>>k;
                m[t].push_back(make_pair(k,j+1));
            }
            sort(m[t].begin(),m[t].end());
        }
        for(auto it = w.begin();it!=w.end();it++){
            cout<<it->first<<"\t";
            for(int i=0;i<n;i++)
                cout<<it->second[i].first<<" : "<<it->second[i].second<<"\t";
            cout<<endl;
        }
        cout<<"\n\n";
        for(auto it = m.begin();it!=m.end();it++){
            cout<<it->first<<"\t";
            for(int i=0;i<n;i++)
                cout<<it->second[i].first<<" : "<<it->second[i].second<<"\t";
            cout<<endl;
        }
    }
}