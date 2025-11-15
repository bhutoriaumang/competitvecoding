/*

Problem Tags: ['constructive algorithms', 'math', 'number theory'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n,m;
        cin>>n>>m;
        if(n%2==0){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<(i+1+(j*n))<<" ";
                }
                cout<<endl;
            }
        }
        else if(m%2==0){
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    cout<<((m*i)+j+1)<<" ";
                }
                cout<<endl;
            }
        }
        else{
            for(int i=0;i<n;i+=2){
                for(int j=0;j<m;j++){
                    cout<<((m*i)+j+1)<<" ";
                }
                cout<<endl;
            }
            for(int i=1;i<n;i+=2){
                for(int j=0;j<m;j++){
                    cout<<((m*i)+j+1)<<" ";
                }
                cout<<endl;
            }
        }
        cout<<endl;
    }
}

/*

16 12  3  9
 7  8  2  1
13  4 10 11
14  5  6 15

 1  2  3  4  5
11 12 13 14 15
21 22 23 24 25
 6  7  8  9 10
16 17 18 19 20


1
3
5
7
2
4
6

*/