#include </Users/bits/stdc++.h>
using namespace std;

bool comparable(vector <int> v1, vector<int> v2, int d){//Comparing two points and returning result based on the given conditions
    int k1 = 0, k2 = 0;
    for(int i=0;i<d;i++){
        if(v1[i]>v2[i])
            k1++;
        else if(v1[i]==v2[i])
            k2++;
    }
    if((k1+k2)==d && k1>0)
        return true;
    else
        return false;
}

void display(vector <int> v, int d){//Printing a point
    for(int i=0;i<d;i++)
        cout<<v[i]<<((i<d-1)?" , ":"\t");
}

void calculate(vector < vector <int> > a,int n,int d){//Finding the different sets where each point belongs and printing the result accordingly
    vector <int> k(n,0),f(n,0);
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(!comparable(a[i],a[j],d)){
                k[j]++;//Maintaing the count of elements which are non comparable with point j
            }
        }
    }
    int tc = 0;
    for(int i=0;i<n-1;i++){
        if(f[i]==0){
            cout << "Group of points are\t:\t";
            int count = 0;
            for(int j=i;j<n;j++){
                if(((k[j]>=(j-tc)) && !comparable(a[i],a[j],d) && f[j]==0) || j==i){//Checking if the ith point is non-comparable to jth point and also checking if the grouping of both these points is the best option available by checking the number of options left with us
                    display(a[j],d);
                    f[j] = 1;
                    count++;
                }
            }
            tc+=count;
            cout<<"\n";
        }
        for(int j=i+1;j<n;j++){
            if(!comparable(a[i],a[j],d))
                k[j]--;//Substracting the options which didn't suit in the previous loop
        }
    }
    if(f[n-1]==0){//To check if the last element is not in the group of anyone and if so print it
        cout << "Group of points are\t:\t";
        display(a[n-1],d);
        cout<<endl;
    }
}

int main(){
    cout << "Enter the number of points followed by the number of dimensions for each point\t:\t";
    int n,d;
    cin>>n>>d;
    vector <vector <int> > a;
    for(int i=0;i<n;i++){
        cout<<"Enter the point "<<(i+1)<<"\t:\t";
        vector <int> temp;
        for(int j=0;j<d;j++){
            int t;
            cin>>t;
            temp.push_back(t);
        }
        a.push_back(temp);
    }
    sort(a.begin(),a.end());//Sorting the given set of points in ascending order
    reverse(a.begin(),a.end());//Reversing the sorted vector to get the set of points in descending order
    calculate(a,n,d);//Calculating answer
}