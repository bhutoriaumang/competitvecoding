/*

Problem Tags: ['dp', 'greedy', 'implementation'] 

*/

#include <iostream>
#include <cmath>
using namespace std;

void lowerbound(long long m,long long s,long long c, int *a){
    if(c<0){
        return;
    }
    if(m==1){
        *a+=s;
        return; 
    }
    if(s-c<0){
        lowerbound(m,s,c-1,a);
        return;
    }
    *(a + m - 1) = c;
    return lowerbound(m-1,s-c,c,a);
}

void upperbound(int m,int s,int c,int*a){
    if(m==0){
        return;
    }
    if(s-c<0){
        upperbound(m,s,c-1,a);
        return;
    }
    *(a-m+1) = c;
    upperbound(m-1,s-c,c,a);
}


int main(){
    long long m,s;
    cin>>m>>s;
    int l[m];
    int u[m];
    l[0] = 1;
    long sum = 0;
    lowerbound(m,s-1,9,l);
    for(int i=0;i<m;i++){
        sum+=l[i]%10;
    }
    if(sum==s && (l[0]!=0 || m==1)){
        for(int i=0;i<m;i++)
            cout<<l[i];
    }
    else
        cout<<"-1";
    cout<<" ";
    upperbound(m,s,9,&l[m-1]);
    sum = 0;
    for(int i=0;i<m;i++){
        sum+=l[i]%10;
    }
    if(sum==s && (l[0]!=0 || m==1)){
        for(int i=0;i<m;i++)
            cout<<l[i];
    }
    else
        cout<<"-1";
    cout<<"\n";
}