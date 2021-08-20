#include <iostream>
using namespace std;


void merge(long arr[], long l, long m, long r,long x[])
{
    long n1 = m - l + 1;
    long n2 = r - m;
    long L[n1], R[n2];
    long Lk[n1], Rk[n2];
    for (long i = 0; i < n1; i++){
        L[i] = arr[l + i];
        Lk[i] = x[l + i];
    }
    for (long j = 0; j < n2; j++){
        R[j] = arr[m + 1 + j];
        Rk[j] = x[m + 1 + j];
    }
    long i = 0;
    long j = 0;
    long k = l;
 
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            x[k] = Lk[i];
            i++;
        }
        else {
            arr[k] = R[j];
            x[k] = Rk[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        x[k] = Lk[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        x[k] = Rk[j];
        j++;
        k++;
    }
}
void mergeSort(long arr[],long l,long r, long x[]){
    if(l>=r){
        return;
    }
    long m =l+ (r-l)/2;
    mergeSort(arr,l,m,x);
    mergeSort(arr,m+1,r,x);
    merge(arr,l,m,r,x);
}

int main(){
    long t;
    cin>>t;
    for(long cas = 1; cas<=t ; cas++){
        long n,x;
        cin>>n>>x;
        long a[n],k[n];
        long s = 0;
        for(long i=0;i<n;i++){
            cin>>a[i];
            k[i] = i+1;
        }
        for(long i=0;i<n;i++){
            a[i] = (long)(a[i]/x);
        }
        mergeSort(a,0,n-1,k);
        cout<<"Case #"<<cas<<": ";
        for(long i=0;i<n;i++){
            cout<<k[i]<<" ";
        }
        cout<<endl;
    }
}