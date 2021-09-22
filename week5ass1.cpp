#include <bits/stdc++.h>
using namespace std;

vector <long long int> mw;
long long int diff = -1000000000;


void search(vector < vector <long long int> > a,vector <long long int> w,vector <long long int> p,long long int root){
    deque <long long int> q;
    vector <long long int> vis(p.size(),0),l(p.size(),0);
  	long long int visited = 1;
    q.push_back(root);
    while(!q.empty()){
        long long int k = q.front();
        q.pop_front();
        if(a[k].size()==0){
            mw[k] = w[k];
            l[p[k]]--;
            if(q.empty() || (l[p[k]]==0))
                q.push_back(p[k]);
        }
        else{
            if(vis[k]==0){
                for(int j=0;j<a[k].size();j++){
                    l[k]++;
                    q.push_back(a[k][j]);
                }
            }
            else{
                for(int j=0;j<a[k].size();j++){
                    diff = max(diff,w[k]-mw[a[k][j]]);
                    mw[k] = min(mw[k],mw[a[k][j]]);
                }
                if(k!=root){
                    l[p[k]]--;
                    if(q.empty() || (l[p[k]]==0))
                        q.push_back(p[k]);
                }
            }
        }
        vis[k] = 1;
    }
}

int main(){
    // fstream file;
    // string filename = "week5input.txt";
    // file.open(filename.c_str());
    long long int n;
    cin>>n;
    vector <long long int> w(n),v(n);
    vector < vector <long long int> > a(n);
    for(long long int i=0;i<n;i++)
        cin>>w[i];
    for(long long int i=0;i<n;i++)
        cin>>v[i];
	if(n==1){
      cout<<"0\n";
      exit(0);
    }
    long long int root = -1;
  	mw.assign(n,-100000000);
    for(long long int i=0;i<n;i++){
      	mw[i] = w[i];
        if(v[i]!=-1){
            v[i]--;
            a[v[i]].push_back(i);
        }
        else
            root = i;
    }
    search(a,w,v,root);
    cout<<diff<<"\n";
}