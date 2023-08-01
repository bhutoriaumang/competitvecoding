#include <bits/stdc++.h>
using namespace std;

int subarray(vector <long long int> arr , long long int n , long long int sum )  {  
    long long int currentsum = arr[ 0 ] , begin = 0 , i ;  
    for ( i = 1 ; i <= n ; i++) {
        while ( currentsum > sum && begin < i - 1) {  
            currentsum = currentsum - arr[ begin ] ;  
            begin++ ;  
        }
        if ( currentsum == sum ) {  
            cout << (begin+1) << " " << (i-begin) << endl ;  
            return (i-begin) ;  
        }
        if (i < n)  
            currentsum = currentsum + arr[ i ] ;  
    }
    return 0 ;  
}  

int main(){
    long long int T;
    T=1;
    while(T-->0){
        long long int n,m,q;
        cin>>n>>m>>q;
        vector <long long int> x(n),y(n);
        for(long long int i=0;i<n;i++){
            x[i] = (i+1)*m + ((i>0) ? (x[i-1]) : 0);
            y[i] = (i+1)*m;
        }
        for(long long int i=0;i<q;i++){
            long long int d;
            cin>>d;
            if(m==1){
                int ans = subarray(y,n,d);
                for(int i=0;i<ans;i++)
                    cout<<"1 ";
                if(ans==0)
                    cout<<"-1";
                cout<<endl;
                continue;
            }
            if(d>((n*m*(n+1))/2)){
                cout<<"-1\n";
                continue;
            }
            long long int p = 0;
            while(x[p]<d){
                cout<<x[p]<<" ";
                p++;
            }
            vector <long long int> ans(p+1,m);
            long long int xx = x[p];
            while((xx-p-1) >= d){
                ans[p]--;
                xx-=(p+1);
            }
            while((xx-1)>=d){
                ans[0]--;
                xx--;
            }
            int j=0,f=0;
            while(ans[j]==0){
                if(ans[j]<0){
                    f=1;
                    break;
                }
                j++;
            }
            if(f){
                cout<<"-1\n";
                continue;
            }
            cout << (j+1) << " " << (p+1-j) << "\n";
            for(;j<ans.size();j++)
                cout<<ans[j]<<" ";
            cout<<endl;
        }
    }
}

/*

3 8 9

4 8 12 12

1

4 8 12 16 20


1 1 1
2 2 2
3 3 3
4 4 4
5 5 5

*/