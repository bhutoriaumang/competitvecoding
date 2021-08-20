#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
    vector <long long int> v(n);
    map <long long int , vector <long long int> > x;
    for(auto &i : v)
        cin>>i;
    for(int i=0;i<n;i++){
        x[v[i]].push_back(i);
    }
    int c=0;
    for(int i=0;i<=n-k;i++){
        if(v[i]==-2)
            continue;
        // auto it = find(v.begin()+i+1,v.begin()+i+k-1,v[i]);
        // while(it!=v.end() && v[it-v.begin()]!=-2){
        //     if(*it!=v[i])
        //         break;
        //     v[it-v.begin()] = -2;
        //     it = find(v.begin()+i+1,v.begin()+i+k-1,v[i]);
        // }
        for(int j=0;j<x[v[i]].size();j++){
            int p = x[v[i]][j];
            if(p<=i)
                continue;
            if(p>=(i+k))
                break;
            v[p] = -2;
        }
        v[i] = -2;
        c++;
    }
    reverse(v.begin(),v.end());
    x.clear();
    for(int i=0;i<n;i++){
        x[v[i]].push_back(i);
    }
    for(int i=0;i<=n-k;i++){
        if(v[i]==-2)
            continue;
        // auto it = find(v.begin()+i+1,v.begin()+i+k-1,v[i]);
        // while(it!=v.end() && v[it-v.begin()]!=-2){
        //     if(*it!=v[i])
        //         break;
        //     v[it-v.begin()] = -2;
        //     it = find(v.begin()+i+1,v.begin()+i+k-1,v[i]);
        // }
        for(int j=0;j<x[v[i]].size();j++){
            int p = x[v[i]][j];
            if(p<=i)
                continue;
            if(p>=(i+k))
                break;
            v[p] = -2;
        }
        v[i] = -2;
        c++;
    }
    cout<<c<<endl;
}