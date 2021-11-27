#include </Users/bits/stdc++.h>
using namespace std;

int main(){
	int n,e;
	cin>>n>>e;
	vector < vector <int> > v(n,vector<int>(n,0));
	vector <int> visited(n,0),parent(n,-1);
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		v[x][y] = 1;
	}
	int s,g;
	cin>>s>>g;
	stack <int> q;
	q.push(s);
	long long int d = 0,ans=n+1;
	while(!q.empty()){
		int x = q.top();
		q.pop();
		d++;
		for(int i=0;i<n;i++){
			if(v[x][i]==1){
				parent[i] = x;
				q.push(i);
                if(i==g){
                    int t = g;
                    while(t!=s){
                        if(t!=s)
			                cout<<t<<" <- ";
                        t = parent[t];
                    }
			        cout<<t<<endl;
                    exit(0);
                }
			}
		}
	}
}