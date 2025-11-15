#include <iostream>
using namespace std;

int main(){
    long long int n;
    cin>>n;
    int c[5];
    for(int i=0;i<5;i++)
        c[i] = 0;
    for(long long int i=0;i<n;i++){
        int t;
        cin>>t;
        if(t==1)
            c[0]++;
        else if(t==2)
            c[1]++;
        else if(t==3)
            c[2]++;
        else if(t==4)
            c[3]++;
        else if(t==6)
            c[4]++;
        else{
            cout<<"-1"<<endl;
            exit(0);
        }
    }
    string s = "";
    if(c[2]>0){
        c[0]-=c[2];
        c[4]-=c[2];
        for(int i=0;i<c[2];i++)
            s+="1 3 6\n";
        c[2] = 0;
    }
    if(c[3]>0){
        c[0]-=c[3];
        c[1]-=c[3];
        for(int i=0;i<c[3];i++)
            s+="1 2 4\n";
        c[3] = 0;
    }
    if(c[4]>0){
        c[0]-=c[4];
        c[1]-=c[4];
        for(int i=0;i<c[4];i++)
            s+="1 2 6\n";
        c[4] = 0;
    }
    for(int i=0;i<5;i++){
        if(c[i]!=0){
            cout<<"-1"<<endl;
            exit(0);
        }
    }
    cout<<s;

}