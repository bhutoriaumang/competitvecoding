#include </Users/bits/stdc++.h>
using namespace std;

long long int KnapSack(vector < pair <long long int,long long int> > v, long long int n, long long int W){
    long long int mat[2][W+1];
    memset(mat, 0, sizeof(mat));
    long long int i = 0;
    while (i < n)
    {
        long long int j = 0;
        if (i%2!=0){
            while (++j <= W){
                if (v[i].first <= j)
                    mat[1][j] = max(v[i].second + mat[0][j-v[i].first],mat[0][j]);
                else
                    mat[1][j] = mat[0][j];
            }
        }
        else{
            while(++j <= W){
                if (v[i].first <= j)
                    mat[0][j] = max(v[i].second + mat[1][j-v[i].first],mat[1][j]);
                else
                    mat[0][j] = mat[1][j];
            }
        }
        i++;
    }
    return (n%2 != 0)? mat[0][W] : mat[1][W];
}

int main(){
    long long int T;
    cin>>T;
    vector <long long int> x(1002,10000);
    x[1] = 0;
    for(long long int i=1;i<=1001;i++){
        for(long long int j=1;j<=i;j++){
            if((i+j)>1001)
                break;
            if(i%j==0)
                x[i+j] = min(x[i]+1,x[i+j]);
        }
    }
    while(T-->0){
        long long int n,k;
        cin>>n>>k;
        long long int ans = 0;
        vector < pair<long long int,long long int> > v(n),d;
        for(long long int i=0;i<n;i++){
            cin>>v[i].first;
            v[i].first = x[v[i].first];
        }
        for(long long int i=0;i<n;i++){
            cin>>v[i].second;
            if(v[i].first==0)
                ans+=v[i].second;
            else
                d.push_back(v[i]);
        }
        cout<<ans+KnapSack(v,n,k)<<endl;
    }
}

/*

1 2 3 4 5 6 7 8 9 10
0 1 2 2 3 3 4 3 4 4

*/