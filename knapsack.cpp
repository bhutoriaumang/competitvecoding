#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int n,W;
    cout<<"Enter the number of items int the bag\t:\t";
    cin>>n;
    cout<<"Enter the capacity of bag\t:\t";
    cin>>W;
    vector <int> w(n),v(n);
    cout<<endl;
    cout<<endl;
    cout<<"Enter the weight of each item\t:\n\n";
    for(int i=0;i<n;i++){
        cout<<"Weight of item "<<(i+1)<<"\t:\t";
        cin>>w[i];
    }
    cout<<endl;
    cout<<endl;
    cout<<"Enter the value of each item\t:\n\n";
    for(int i=0;i<n;i++){
        cout<<"Value of item "<<(i+1)<<"\t:\t";
        cin>>v[i];
    }
    cout<<endl;
    cout<<endl;
    vector < vector <int> > x(n+1,vector<int>(W+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(w[i-1]>j)
                x[i][j] = x[i-1][j];
            else
                x[i][j] = max(x[i-1][j],x[i-1][j-w[i-1]]+v[i-1]);
        }
    }
    cout<<"The maximum value to be carried is\t:\t"<<x[n][W]<<endl;
}