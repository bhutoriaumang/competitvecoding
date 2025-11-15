/*

Problem Tags: ['constructive algorithms', 'math'] 

*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> v(n);
        for(int i=0;i<n;i++)
            v[i]=i+1;
        cout<<n<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                cout<<v[j]<<" ";
            cout<<endl;
            swap(v[n-1-i],v[n-2-i]);
        }
    }
}

/*

1 2 3 4 5
1 2 3 5 4
1 2 5 3 4
1 5 2 3 4



*/