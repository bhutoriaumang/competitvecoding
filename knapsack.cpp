#include </Users/bits/stdc++.h>
using namespace std;

int main(){
    int n,W;

    //Taking input from user
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

    //Calculating the best possible ans

    vector < vector <int> > x(n+1,vector<int>(W+1,0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=W;j++){
            if(w[i-1]>j)
                x[i][j] = x[i-1][j];//If weight of item is greater than what we can carry , the value of the particular pair stays the same as the previous pair
            else
                x[i][j] = max(x[i-1][j],x[i-1][j-w[i-1]]+v[i-1]);//If weight of the current item is less than equal to what we can carry , we find the max value possible by comparing the value of the previous pair and the value found after adding the current item
        }
    }
    cout<<"The maximum value to be carried is\t:\t"<<x[n][W]<<endl;
}