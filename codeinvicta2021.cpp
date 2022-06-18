#include </Users/bits/stdc++.h>
using namespace std;

int getClosest(int, int, int,vector <int>);
int findClosest(vector<int> arr, int n, int target)
{
    if (target <= arr[0])
        return 0;
    if (target >= arr[n - 1])
        return (n - 1);
    int i = 0, j = n, mid = 0;
    while (i < j) {
        mid = (i + j) / 2;
        if (arr[mid] == target)
            return mid;
        if (target < arr[mid]) {
            if (mid > 0 && target > arr[mid - 1])
                return getClosest(mid - 1,mid, target,arr);
            j = mid;
        }
        else {
            if (mid < n - 1 && target < arr[mid + 1])
                return getClosest(mid,mid + 1, target,arr);
            i = mid + 1;
        }
    }
    cout<<mid<<endl;
    return mid;
}
int getClosest(int val1, int val2,int target,vector <int> arr)
{
    if (target - arr[val1] >= arr[val2] - target)
        return val2;
    else
        return val1;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        int n;
        cin>>n;
        vector <int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
            a[i]%=n;
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            b[i]%=n;
        }
        sort(b.begin(),b.end());
        for(int i=0;i<a.size();i++)
            cout<<a[i]<<" ";
        cout<<endl;
        for(int i=0;i<n;i++){
            int x = findClosest(b,b.size(),n-a[i]);
            int y = findClosest(b,b.size(),0);
            if(((a[i]+b[x])%n) < ((a[i]+b[y])%n)){
                cout<< ((a[i]+b[x])%n) << ":" << b[x] << "," << b[y] << " ";
                b[x] = -1000;
                b.erase(b.begin()+x,b.begin()+x+1);
            }
            else{
                cout<< ((a[i]+b[y])%n) << ":" << b[y] << "`" << b[x] << " ";
                b.erase(b.begin()+y,b.begin()+y+1);
            }
            cout<<endl;
            for(int i=0;i<b.size();i++)
                cout<<b[i]<<" ";
            cout<<endl;
        }
        cout<<endl;
    }
}