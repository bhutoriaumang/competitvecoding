#include </Users/bits/stdc++.h>
using namespace std;

int main(){
	int n,e;
	cout<<"Enter the number of vertices and edges of the graph:\t";
	cin>>n>>e;
	vector < vector <int> > v(n,vector<int>(n,0));
	vector <int> visited(n,0),parent(n,-1);
	cout<<"Ente the edges"<<endl;
	for(int i=0;i<e;i++){
		int x,y;
		cin>>x>>y;
		v[x][y] = 1;
	}
	int s,g;
	cout<<"Enter the source and goal vertices:\t";
	cin>>s>>g;
	queue <int> q;
	q.push(s);
	long long int d = 0,ans=n+1;
	while(!q.empty()){
		int x = q.front();
		visited[x] = 1;
		q.pop();
		d++;
		for(int i=0;i<n;i++){
			if(visited[i])
				continue;
			if(v[x][i]==1){
				parent[i] = x;
				q.push(i);
			}
		}
	}
	int x = g;
	cout<<"The path found from BFS search is:\t"
	while(x!=-1){
		if(x!=s)
			cout<<x<<" <- ";
		else
			cout<<x<<endl;;
		x = parent[x];
	}
}