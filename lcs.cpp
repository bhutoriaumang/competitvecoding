#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cout<<"Enter string 1\t:\t";
    cin>>a;
    cout<<"Enter string 2\t:\t";
    cin>>b;
    cout<<"\n\n";
    int x=a.length();
    int y=b.length();
    vector < vector <int> > c(x+1,vector<int>(y+1,0));
    vector < vector <int> > d(x+1,vector<int>(y+1,0));
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(a[i]==b[j]){
                c[i+1][j+1] = c[i][j]+1;
                d[i+1][j+1] = 1;
            }
            else{
                c[i+1][j+1] = max(c[i+1][j],c[i][j+1]);
                d[i+1][j+1] = (c[i+1][j]>=c[i][j+1])?2:3;
            }
        }
    }
    if(c[x][y]==0){
        cout<<"There is no common subsequence\n";
        exit(0);
    }
    cout<<"The length of the longest common subsequence\tis :\t"<<c[x][y]<<"\n\n";
    cout<<"The longest subsequence is\t:\t";
    int i=x,j=y;
    string s = "";
    while(i!=0 && j!=0){
        if(d[i][j]==1){
            i--;
            j--;
            s = a[i]+s;
        }
        else if(d[i][j]==3)
            i--;
        else
            j--;
    }
    cout<<s<<endl;
}
