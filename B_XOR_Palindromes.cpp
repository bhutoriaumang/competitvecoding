/*

Problem Tags: ['bitmasks', 'constructive algorithms', 'strings'] 

*/

#include <bits/stdc++.h>
using namespace std;

void print(vector <int> v){
    for(int i=0;i<v.size();i++)
        cout<<v[i];
    cout<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int a=0,b=0;
        for(int i=0;i<n/2;i++){
            if(s[i]==s[n-i-1])
                b++;
            else
                a++;
        }
        vector <int> v(n+1,0);
        v[a]=1;
        while(b-->0){
            a+=2;
            if(a>(n+1))
                break;
            v[a]=1;
        }
        if(n%2==1){
            for(int i=n-1;i>=0;i--){
                if(v[i]==1)
                    v[i+1]=1;
            }
        }
        print(v);
    }
}

/*

00001100
2
0011111100
*/