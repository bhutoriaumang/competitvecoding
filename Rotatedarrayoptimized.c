#include <stdio.h>
#include <stdlib.h>

int count = 0;

int RotatedArraySearch(int a[],int l, int u, int k){
    count ++;
    if(l>u)
        return -1;
    int m = l + (u-l)/2;
    if(a[m]==k)
        return m;
    else if(a[m]<a[u] && a[m]<k && a[u]>=k)
        return RotatedArraySearch(a,m+1,u,k);
    else if(a[m]>a[l] && a[m]>k && a[l]<=k)
        return RotatedArraySearch(a,l,m-1,k);
    else if(a[m]<a[u])
        return RotatedArraySearch(a,l,m-1,k);
    else
        return RotatedArraySearch(a,m+1,u,k);
}

int BinarySearch(int a[],int l, int u, int k){
    count++;
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
        count++;
        if(a[i]==k)
            return i;
    }
    return -1;
}

int main(){
    int n,k,c,p;
    printf("Enter 1 to perform search on an unsorted array\n2 to perform search on sorted array\n3 to search on rotated array\n> ");
    scanf("%d",&c);
    printf("Enter the size of the array : ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter element %d of the array : ",i+1);
        scanf("%d",&a[i]);
    }
    printf("Enter the element to be searched : ");
    scanf("%d",&k);
    if(c==1)
        p = LinerSearch(a,n,k);
    else if(c==2)
        p = BinarySearch(a,0,n-1,k);
    else
        p = RotatedArraySearch(a,0,n-1,k);
    if(p!=-1)
        printf("Position of the given element is: %d\n",p+1);
    else
        printf("Element not found\n");
    printf("The number of comparisons made : %d\n",count);
}

/*
    For subpart 1, the approach used is Linear Search where the array is traversed sequentially, checking each element one by one until we find the key element. The upper bound of this algorithm is O(n).

    For subpart 2, the approach used is Binary Search in which the size of the array where the element is to be checked is reduced to half after each comparison until we find the key element. The upper bound of the algorithm is O(log n).

    For subpart 3, a special function RotatedArraySearch is used where the task of finding the pivot element at which the array is rotated and the task to find the key element is combined to make an optimized search. Similar to Binary Search , the size of the array here too is reduced to half after each comparison. The upper bound is O(log n) for this algorithm too.
*/