#include <iostream>
#include <set>
#include <vector>
#include <assert.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t-->0){
		ios_base::sync_with_stdio(false);
		long long int n,m;
		cin>>n>>m;
		assert(1<=n && n<=100000);
    	assert(1<=m && m<=100000);
		vector <long long int> v(n+m);
		set <long long int> s;
		for(long long int i=0;i<n+m;i++){
			cin>>v[i];
			assert(0<= v[i] && v[i]<= 1000000000000);
		}
		for(int i=0;i<n;i++){
			s.insert(v[i]);
		}
		for(int i=n;i<n+m;i++){
			if(s.find(v[i])!=s.end())
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
			s.insert(v[i]);
		}
		
	}
}