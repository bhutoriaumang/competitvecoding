#include <stdio.h>

int FindPivot(int a[],int l, int u){
    if(l>u)
        return 0;
    int m = l + (u-l)/2;
    if(u-l==1)
        return l;
    if(a[m]>a[l])
        return FindPivot(a,m,u);
    else
        return FindPivot(a,l,m);
}

int BinarySearch(int a[],int l, int u, int k){
    if(l>u)
        return -1;
    int m = l + (int)((u-l)/2);
    if(a[m]>k)
        return BinarySearch(a,l,m-1,k);
    else if(a[m]<k)
        return BinarySearch(a,m+1,u,k);
    else
        return m;
}

int LinerSearch(int a[], int n, int k){
    for(int i=0;i<n;i++){
        if(a[i]==k)
            return i;
    }
    return -1;
}

int main(){
    int n,k,c;
    printf("Enter 1 to perform search on an unsorted array\n2 to perform search on sorted array\n3 to search on rotated array\n> ");
    scanf("%d",&c);
    printf("Enter the size of the array");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d of the array : ",i+1);
        scanf("%d",&a[i]);
    }
    scanf("%d",&k);
    int p = FindPivot(a,0,n-1);
    if(p==n-1)
        printf("%d",BinarySearch(a,0,n-1,k));
    else if(a[0]<=k)
        printf("%d",BinarySearch(a,0,p,k));
    else if(a[n-1]>=k)
        printf("%d",BinarySearch(a,p+1,n-1,k));
}