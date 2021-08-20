#include </Users/bits/stdc++.h>
using namespace std;

list<int> construct(int n,int s,int x){
    if(n==1){
        return list<int> (1,x);
    }
    if((s-1)>=(n-2) && (s-1)<= ((n*(n-1))/2-1)){
        list <int> arr = construct(n-1,s-1,x+1);
        arr.push_front(x);
        return arr;
    }
    else{
        int d = int(s - (n*(n-1))/2 + 1);
        list <int> a = construct(n-1,s-d,x+1);
        list<int> ::iterator end = a.begin();
        advance(end,d-1);
        reverse(a.begin(),end);
        a.insert(end,x);
        return a;
    }
}

int main(){
    int t;
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        cout<<"Case #"<<cas<<": ";
        int n,s;
        cin>>n>>s;
        vector <int> a;
        for(int i=0;i<n;i++)
            a.push_back(i+1);
        
        if(s<(n-1) || s>((n*(n+1))/2 - 1)){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        list <int> ans = construct(n,s,1);
        for(auto i:ans){
            cout<< (i) <<" ";
        }
        cout<<"\n";
    }
}

/*

    1   2   3   4   5   6   7       0
    7   6   5   4   3   2   1       7
    7   6   5   4   3   2   1       12


    1   2   3   4   0
    4   3   2   1   4
    4   3   2   1   6

    1   2   3   4   5   6   7       0

    
*/