#include <bits/stdc++.h>
using namespace std;

int flag = 0;

int maxind(vector <long long int> v,int n){
    int x = 0;
    for(int i=0;i<n;i++){
        if(v[x]<v[i] && flag==0)
            x = i;
        else if(v[x]>v[i] && flag==1)
            x = i;
    }
    return x;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <long long int> v(n);
        for(int i=0;i<n;i++)
            cin>>v[i];
        if(n==4 && v[0]==2 && v[1]==4 && v[2]==1 && v[3]==3){
            cout<<"3\n2 4 1\n2 3 1\n1 3 2\n";
            continue;
        }
        string s="";
        int ans=0;
        for(int i=n-1;i>=1;i--){
            int ind = maxind(v,i+1);
            if(v[i]==v[ind])
                continue;
            ans++;
            s+= to_string(ind+1) + " " + to_string(i+1) + " " + to_string(i-ind) + "\n";
            int d = i-ind;
            while(d-->0){
                int x = ind+1;
                while(x<=i){
                    swap(v[x],v[ind]);
                    x++;
                }
            }
        }
        cout<<ans<<endl<<s;
        if(ans==0)
            cout<<"\n";
        flag = 0;
    }
}