#include <stdio.h>

void mergesort(int a[],int st, int end);
void merge(int a[],int st,int mid, int end);

void mergesort(int a[],int st, int end){
    if(st<end){
        int mid = (st+end)/2;
        mergesort(a,st,mid);
        mergesort(a,mid+1,end);
        merge(a,st,mid,end);
    }
}

void merge(int a[],int st,int mid, int end){
    int l = mid-st+1,r= end - mid;
    int x[l],y[r];
    int i=0,j=0,k=st;
    while(i<l){
        x[i] = a[st+i];
        i++;
    }
    i = 0;
    while(i<r){
        y[i] = a[mid+1+i];
        i++;
    }
    i = 0;
    while(i<l && j<r){
        if(x[i]<=y[j])
            a[k++] = x[i++];
        else if(x[i]>y[j])
            a[k++] = y[j++];
    }
    while(i<l)
        a[k++] = x[i++];
    while(j<r)
        a[k++] = y[j++];
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
    mergesort(a,0,n-1);
    for(int i=0;i<n;i++)
        printf("%d ",a[i]);
    printf("\n");
}