// #include </Users/bits/stdc++.h>
// using namespace std;

// vector <long long int> prime(1000000+1,0);
// vector <long long int> x(1000000+1,0);

// void sieve(){
// 	long long int n = 1000000;
// 	for(long long int i=2;(i)<=n;i++){
// 		if(prime[i]==0){
// 			for(long long int j=i+i;j<=n;j+=i){
// 				prime[j] = 1;
// 			}
// 		}
// 	}
// 	for(int i=2;i*i<=n;i++){
// 		x[i] = 1;
// 		if(prime[i]==1){
// 			long long int k = i,c=0,t=2;
// 			while(k>1){
// 				if(k%t==0){
// 					c++;
// 					k/=t;
// 				}
// 				else{
// 					x[i]*= (c+1);
// 					c = 0;
// 					t++;
// 				}
// 			}
// 			x[i]*= (2*c+1);
// 		}
// 		else{
// 			x[i] = 3;
// 		}
// 	}
// }


// int main(){
// 	sieve();
// 	ofstream MyFile("code2.txt");
//     int t;
//     cin>>t;
//     while(t-->0){
//         long long int n,c=0;
//         cin>>n;
//         for(long long int i=1;i<sqrt(n);i++){
//             if(x[i]%2==1 && prime[x[i]]==0){
// 				c++;
//                 MyFile<<i*i<<"\n";
// 			}
//         }
// 		cout<<c<<endl;
//     }
// }


#include </Users/bits/stdc++.h>
using namespace std;

vector <long long int> prime(1000000+1,0);
vector <long long int> x(1000000+1,0);

void sieve(){
	long long int n = 1000000;
	for(int i=2;(i)<=n;i++){
		if(prime[i]==0){
			for(int j=i+i;j<=n;j+=i){
				double s = ((float)(log(j)/log(i)) - (float)floor(log(j)/log(i)));
				if(s==0.0 || s==1.0)
					prime[j] = 2*(float)((log(j)/log(i))) + 1;
				else
					prime[j] = -1;
			}
			prime[i] = 3;
		}
	}
}

int main(){
	sieve();
	// ofstream MyFile("code1.txt");
	int t;
	cin>>t;
	while(t-->0){
		long long int n,c=0;
		cin>>n;
		for(long long int i=2;i<=floor(sqrt(n));i++){
			if(prime[prime[i]]==3 && prime[i]!=-1){
				// MyFile<<i*i<<endl;
				c++;
			}
		}
		cout<<c<<endl;
	}
}

/*

	n = p^k

*/