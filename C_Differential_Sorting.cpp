/*

Problem Tags: ['constructive algorithms', 'greedy'] 

*/

#include <bits/stdc++.h>
using namespace std;

void display(vector <long long int> v ){
    for(int i=0;i<v.size();i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <long long int> v(n);
        vector < vector <int> > ans;
        for(int i=0;i<n;i++)
            cin>>v[i];
        long long int x = n-1;
        if(v[n-2]<v[n-1] && v[n-2]>0)
            x = n-2;
        for(int i=n-3;i>=0;i--){
            if(v[i]>v[i+1]){
                if(x!=(i+1)){
                    v[i] = v[i+1] - v[x];
                    vector <int> temp;
                    temp.push_back(i+1);
                    temp.push_back(i+2);
                    temp.push_back(x+1);
                    ans.push_back(temp);
                }
                else{
                    v[i] = v[i+1] - v[x+1];
                    vector <int> temp;
                    temp.push_back(i+1);
                    temp.push_back(i+2);
                    temp.push_back(x+2);
                    ans.push_back(temp);
                }
            }
            if(v[i]>0 && v[i]<x)
                x = i;
        }
        int f = 0;
        for(int i=0;i<v.size()-1;i++){
            if(v[i]>v[i+1]){
                f = 1;
                break;
            }
        }
        if(f==0){
            cout<<ans.size()<<endl;;
            for(int i=0;i<ans.size();i++)
                cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<" \n";
            // display(v);
        }
        else
            cout<<"-1\n";
    }
}