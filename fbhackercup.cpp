#include <bits/stdc++.h>
using namespace std;

int main(){
    fstream input;
    string filename = "facebookhackercupinput1.txt";
    input.open(filename.c_str());
    ofstream file("facebookhackercupoutput1.txt");
    int T;
    input>>T;
    for(int cas = 1;cas<=T;cas++){
        int n;
        input>>n;
        string s;
        input>>s;
        int sum = 0,f=-1;
        for(int i=0;i<n;i++){
            if(f==-1){
                if(s[i]=='O')
                    f = 0;
                else if(s[i]=='X')
                    f = 1;
            }
            else{
                if(s[i]=='O' && f==1){
                    f = 0;
                    sum++;
                }
                else if(s[i]=='X' && f==0){
                    f = 1;
                    sum++;
                }
            }
        }
        file<<"Case #"<<cas<<": "<<sum<<endl;
    }
}