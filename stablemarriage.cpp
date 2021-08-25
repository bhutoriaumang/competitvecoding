#include </Users/bits/stdc++.h>
using namespace std;

bool singlesremain(int *wf,int n){
    if(find(wf,wf+n,-1)==wf+n){
        return false;
    }
    return true;
}

int getrank(vector <int> w, int x,int n){
    return n - (find(w.begin(),w.end(),x)-w.begin());
}

void match(int w,int m, int *mf , int *wf){
    wf[w] = m;
    mf[m] = w;
}

void solve(vector<int> *m,vector<int> *w,int n){
    int wf[n],mf[n];
    for(int i=0;i<n;i++){
        wf[i]=-1;
        mf[i]=-1;
    }
    while(singlesremain(wf,n)){
        for(int i=0;i<n;i++){
            if(mf[i]==-1){
                int x = m[i].back() - 1;
                m[i].pop_back();
                if(wf[x]==-1){
                    match(x,i,mf,wf);
                }
                else{
                    int y = wf[x];
                    if(getrank(w[x],y+1,n) > getrank(w[x],i+1,n)){
                        match(x,i,mf,wf);
                        mf[y] = -1;
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<i+1<<" "<<mf[i]+1<<"\n";
    }
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> m[n],w[n];
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            for(int j=0;j<n;j++){
                cin>>x;
                w[i].push_back(x);
            }
            reverse(w[i].begin(),w[i].end());
        }
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            for(int j=0;j<n;j++){
                cin>>x;
                m[i].push_back(x);
            }
            reverse(m[i].begin(),m[i].end());
        }
        solve(m,w,n);
    }
}