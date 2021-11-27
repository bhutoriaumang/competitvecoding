#include </Users/bits/stdc++.h>
using namespace std;

int main(){

    //Taking input from user
    string a,b;
    cout<<"Enter string 1\t:\t";
    cin>>a;
    cout<<"Enter string 2\t:\t";
    cin>>b;
    cout<<"\n\n";

    //Calculating the DP table of values
    int x=a.length();
    int y=b.length();
    int c[x+1][y+1],d[x+1][y+1];
    for(int i=0;i<=x;i++){
        for(int j=0;j<=y;j++){
            c[i][j] = 0;
            d[i][j] = 0;
        }
    }
    for(int i=0;i<x;i++){
        for(int j=0;j<y;j++){
            if(a[i]==b[j]){//If the two characters are same we add 1 to the value of the cell present at the previous row and column
                c[i+1][j+1] = c[i][j]+1;
                d[i+1][j+1] = 1;
            }
            else{//If the characters don't match we take the max value among the cell present in the previous row and same column and the previous column but same row
                c[i+1][j+1] = max(c[i+1][j],c[i][j+1]);
                d[i+1][j+1] = (c[i+1][j]>=c[i][j+1])?2:3;
            }
        }
    }

    if(c[x][y]==0){//If the value at bottom right cell of the table is 0 it means the two strings are completely distinct and hence there is no common subsequence present
        cout<<"There is no common subsequence\n";
        exit(0);
    }

    cout<<"The length of the longest common subsequence\tis :\t"<<c[x][y]<<"\n\n";
    cout<<"The longest subsequence is\t:\t";
    int i=x,j=y;
    string s = "";
    while(i!=0 && j!=0){//Loop to find the longest common subsequence by following the dimensions we stored previously
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
