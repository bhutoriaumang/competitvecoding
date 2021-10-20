#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    long long int m = 1000000000 + 7;
    int T;
    cin>>T;
    while(T-->0){
        int n,m;
        cin>>n>>m;
        int a[n][m];
        for(int i=0;i<n;i++){
            char c;
            for(int j=0;j<m;j++){
                cin>>c;
                a[i][j] = (c=='1')?1:0;
            }
        }
        vector < vector <int> > v(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            int s = 0;
            for(int j=0;j<m;j++){
                if(a[i][j])
                    s++;
                v[i][j] = s;
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout<<v[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
}

/*


0   0   1   0   1   0   0   0   1
1   0   1   1   1   0   1   0   0
0   0   0   0   1   0   0   1   1
1   0   0   0   0   0   0   0   1
1   0   1   0   1   0   1   0   1
1   1   0   0   0   1   1   1   1
0   0   0   0   0   1   1   1   1
1   1   1   1   0   0   0   0   0
0   0   0   1   1   0   0   0   0

0	0	1	1	2	2	2	2	3	
1	1	2	3	4	4	5	5	5	
0	0	0	0	1	1	1	2	3	
1	1	1	1	1	1	1	1	2	
1	1	2	2	3	3	4	4	5	
1	2	2	2	2	3	4	5	6	
0	0	0	0	0	1	2	3	4	
1	2	3	4	4	4	4	4	4	
0	0	0	1	2	2	2	2	2


*/