/*

Problem Tags: ['brute force', 'dp', 'greedy', 'math'] 

*/

#include <bits/stdc++.h>
using namespace std;

void display(vector <long long int> x){
    for(int i=0;i<x.size();i++)
        cout<<x[i]<<" ";
    cout<<endl;
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
        long long int ans = 0;
        vector <vector <long long int> > d;
        vector <long long int> temp(n+1,0);
        for(int i=1;i<=n;i++){
            temp.clear();
            for(int j=0;j<=n-i;j++){
                vector <long long int> t;
                for(int k=0;k<i;k++){
                    t.push_back(v[j+k]);
                }
                sort(t.begin(),t.end());
                int x = 0;
                for(int k=0;k<t.size();k++){
                    if(t[k]==x)
                        x++;
                    else
                        break;
                }
                temp.push_back(x);
            }
            d.push_back(temp);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<n-i;j++){
                if(i==0){
                    ans+= 1+d[i][j];
                }
                else{
                    long long int x = 0;
                    for(int k=j;k<=j+i;k++)
                        x+=d[0][k];
                    ans+= max(1+d[i][j],i+1+x);
                }
            }
        }
        cout<<ans<<endl;
    }
}