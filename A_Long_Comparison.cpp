#include <bits/stdc++.h>
using namespace std;

int sizeofnum(long long int x){
    int c = 0;
    while(x>0){
        c++;
        x/=10;
    }
    return c;
}

long long int portion(long long int x,long long int t){
    return (long long int)stoi(to_string(x).substr(0,t));
}

void compare(string s1,string s2){
    int f = -1;
    for(int i=0;i<s1.length();i++){
        if(s1[i]>s2[i]){
            f = 0;
            break;
        }
        else if(s1[i]<s2[i]){
            f = 1;
            break;
        }
    }
    if(f==-1)
        cout<<"=";
    else if(f==0)
        cout<<">";
    else
        cout<<"<";
}


int main(){
    int T;
    cin>>T;
    while(T-->0){
        long long int x1,x2,p1,p2;
        cin>>x1>>p1;
        cin>>x2>>p2;
        long long int d1 = sizeofnum(x1)+p1;
        long long int d2 = sizeofnum(x2)+p2;
        string s1 = to_string(x1);
        string s2 = to_string(x2);
        if(d1>d2)
            cout<<">";
        else if(d1<d2)
            cout<<"<";
        else{
            if(p1>p2){
                while(p2<p1){
                    p1--;
                    s1+='0';
                }
            }
            else if(p1<p2){
                while(p1<p2){
                    p2--;
                    s2+='0';
                }
            }
            compare(s1,s2);
        }
        cout<<endl;
    }
}