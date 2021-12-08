#include </Users/bits/stdc++.h>
using namespace std;

#define R 6
#define C 6

vector < vector <int> > sum;
int cou = 0;

void summatrix(char a[R][C],int r,int c){

    r+=2;
    c+=2;
    int s=0;
    for(int i=r-2;i<=r;i++){
        for(int j=c-2;j<=c;j++)
            s+= (int)a[i][j] - 48;
    }
    vector <int> x;
    x.push_back(s);
    x.push_back(r);
    x.push_back(c);
    sum.push_back(x);
    cou++;
}

void printmatrix(char a[R][C],int r,int c){
    for(int i=r-2;i<=r;i++){
        for(int j=c-2;j<=c;j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}

void counterClockspiralPrint(int m,int n,char a[R][C]){
    char arr[4][4];
    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++)
            arr[i][j] = a[i+2][j+2];
    }
    int i, k = 0, l = 0;
    int cnt = 0;
    int total = m * n;
    while (k < m && l < n)
    {
        if (cnt == total)
            break;
        for (i = k; i < m; ++i){
            summatrix(a,i,l);
            cnt++;
        }
        l++;
        if (cnt == total)
            break;
        for (i = l; i < n; ++i){
            summatrix(a,m-1,i);
            cnt++;
        }
        m--;
        if (cnt == total)
            break;
        if (k < m){
            for (i = m - 1; i >= k; --i)
            {
                summatrix(a,i,n-1);
                cnt++;
            }
            n--;
        }
        if (cnt == total)
            break;
        if (l < n){
            for (i = n - 1; i >= l; --i){
                summatrix(a,k,i);
                cnt++;
            }
            k++;
        }
    }
}

int main(){
    string s;
    cin>>s;
    int n = s.length();
    char a[6][6];
    int k = 0;
    for(int i=0;i<6;i++){
        for(int j=0;j<6;j++){
            a[i][j] = s[k++];
            k = k%n;
        }
   }
    vector < vector <int> > f(6,vector <int> (6,0));
    counterClockspiralPrint(4,4,a);
    sort(sum.begin(),sum.end());
    int i=0;
    while(i<sum.size()-1){
        vector < pair <int,int> > x;
        x.push_back(make_pair(sum[i][1],sum[i][2]));
        while(i<sum.size()-1 && sum[i][0]==sum[i+1][0]){
            i++;
            x.push_back(make_pair(sum[i][1],sum[i][2]));
        }
        if(x.size()>1){
            cout << "Sum :\t"<<sum[i][0]<<endl<<endl;
            for(int j=0;j<x.size();j++)
                printmatrix(a,x[j].first,x[j].second);
        }
        i++;
    }
}

/*

6 2 9 0 3 4 
0 4 5 6 6 2 
9 0 3 4 0 4 
5 6 6 2 9 0 
3 4 0 4 5 6 
6 2 9 0 3 4

5,5

2 9 0
4 5 6
0 3 4

*/