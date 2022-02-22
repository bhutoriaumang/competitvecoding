#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    cout<<setprecision(10);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <long long int> v(n);
        long long int sum = 0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            sum+=v[i];
        }
        sort(v.begin(),v.end());
        double mean = (double)sum/(double)n,median=v[ceil((double)n/2.0)-1];
        long long int ans = 0;
        cout<<mean<<" "<<median<<endl;
        if(mean<median){
            ans = (n*median) - sum;
        }
        else if(mean>median){
            double t = mean-median;
            ans = ceil((double)(t*n)/(double)(n-1));
        }
        else
            ans = 0;
        cout<<(ans)<<endl;
    }
}

/*

Mean:   x
Median: y

x<y
(nx+t)/n = y

x>y
y-x=t
(y+t+r) = (nx+t)/n 
t/((n-1)/n)
tn/(n-1)
*/