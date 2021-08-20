#include <iostream>
#include <cmath>
using namespace std;

void display(int n, int m, int *a){
	for(int i=0;i<n;i++){
	    for(int j=0;j<m;j++)
	        cout<<*(a + i*m + j)<<"\t";
	    cout<<endl;
	}
}

int main() {
	int t;
	cin>>t;
	while(t-->0){
	    int n,m,k;
	    cin>>n>>m>>k;
	    int a[n][m],s[n+1][m+1];
	    for(int i=0;i<n;i++){
			int sum = 0;
			s[i][0] = 0;
	        for(int j=0;j<m;j++){
	            cin>>a[i][j];
	            a[i][j]-=k;
				sum+=a[i][j];
				s[i][j+1] = sum;
	        }
	    }
	    display(n,m,&a[0][0]);
		cout<<endl;
	    display(n,m,&s[0][0]);
		for(int t=1;t<=min(n,m);t++){
			int i=0;
			for(int j=1;j<=m;j++){
				int sum = 0;
				
			}
		}
	}
	return 0;
}