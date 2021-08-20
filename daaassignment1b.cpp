#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isEqual(vector <int> v1, vector <int> v2, int d){
    for(int i=0;i<d;i++){
        if(v1[i]!=v2[i])
            return false;
    }
    return true;
}

int main(){
    int n,d;
    cin>>n>>d;
    vector <vector <int> > v,a;
    for(int i=0;i<n;i++){
        vector <int> temp;
        for(int j=0;j<d;j++){
            int k;
            cin>>k;
            temp.push_back(k);
        }
        v.push_back(temp);
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n-1;i++){
        while(isEqual(v[i],v[i+1],d)){
            i++;
        }
        a.push_back(v[i]);
    }
    if(!isEqual(v[n-1],v[n-2],d))
        a.push_back(v[n-1]);
    
}

/*
    a   b   c   d   e   f   .....
    a   :   b,d,f
    b   :   e,f
    d   :   

*/