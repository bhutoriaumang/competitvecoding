#include <bits/stdc++.h>
using namespace std;

long long int getClosest(long long int, long long int, long long int);
long long int findClosest(vector <long long int> arr,long long int n, long long int target){
    if (target <= arr[0])
        return arr[0];
    if (target >= arr[n - 1])
        return arr[n - 1];
    long long int i = 0, j = n, mid = 0;
    while (i < j) {
        mid = (i + j) / 2;
        if (arr[mid] == target)
            return arr[mid];
        if (target < arr[mid]) {
            if (mid > 0 && target > arr[mid - 1])
                return getClosest(arr[mid - 1],arr[mid], target);
            j = mid;
        }
        else {
            if (mid < n - 1 && target < arr[mid + 1])
                return getClosest(arr[mid],arr[mid + 1], target);
            i = mid + 1;
        }
    }
    return arr[mid];
}
long long int getClosest(long long int val1, long long int val2,long long int target){
    if (target - val1 >= val2 - target)
        return val2;
    else
        return val1;
}

int main(){
    int T;
    cin>>T;
    for(int cas=1;cas<=T;cas++){
        long long int n,p;
        vector < vector <long long int> > v(n,vector <long long int>(p,0)),a(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++)
                cin>>v[i][j];
            sort(v[i].begin(),v[i].end());
            
        }
        long long int ans = (v[0][p-1] - v[0][0]),l=0;
        for(int i=1;i<n;i++){
            long long m = 1e15;
            for(int j=0;j<p;j++){
                long long int x = findCloseset(v[i-1],p,v[i][j]);
                m = min()
            }
        }
        cout << "Case #" << cas << ": " << "\n";
    }
}