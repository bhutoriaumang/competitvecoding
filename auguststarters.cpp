#include </Users/bits/stdc++.h>
using namespace std;

int main() {
	int T;
	cin>>T;
	while(T-->0){
	    int n;
	    cin>>n;
	    vector <long long int> a(n),b(n);
	    vector <string> x,y;
	    for(int i=0;i<n;i++){
	        cin>>a[i];
	        x.push_back(bitset<30>(a[i]).to_string());
	    }
	    for(int i=0;i<n;i++){
	        cin>>b[i];
	        y.push_back(bitset<30>(b[i]).to_string());
	    }
	    vector <int> k(30,1),f(30,0);
	    int co = 0;
	    for(int i=0;i<30;i++){
	        for(int j=0;j<n;j++){
	            if(f[j]==0){
	                if(x[j][i]=='0' && y[j][i]=='0')
	                    k[i] = 0;
	                else if(x[j][i]=='1' && y[j][i]=='1')
	                    k[i] = k[i] & 1;
	                else if(k[i]==1){
	                    if(x[j][i]=='1'){
	                        f[j] = 1;
	                    }
	                    else if(y[j][i]=='1'){
	                        f[j] = 2;
	                        co++;
	                    }
	                }
	            }
	            else if(f[j]==1)
	                k[i] = k[i] & x[j][i];
	            else
	                k[i] = k[i] & y[j][i];
	        }
	    }
	    long long int s=0,t=1;
	    for(int i=29;i>=0;i--){
	        s+= (t*k[i]);
	        t*=2;
	    }
	    cout<<s<<" "<<co<<endl;
	}
	return 0;
}