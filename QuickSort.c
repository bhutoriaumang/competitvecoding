#include <stdio.h>
#include <stdlib.h>

int partition(int a[],int s,int e){
    int pivot = a[s];
    int i = s;
    for(int j=s;j<e;j++){
        if(a[j]<pivot){
            int t = a[i];
            a[i] = a[j];
            a[j] = t;
            i++;
        }
    }
    int t = a[i];
    a[i] = a[e];
    a[e] = t;
    return i;
}

void QuickSort(int a[],int s, int e){
    int p;
    if(s<e){
        p = partition(a,s,e);
        QuickSort(a,s,p-1);
        QuickSort(a,p+1,e);
    }
}

int main(){
    int n;
    printf("Enter the size: ");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("The array is: \n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
    QuickSort(a,0,n-1);
    printf("The array is: \n");
    for(int i=0;i<n;i++){
        printf("%d\t",a[i]);
    }
    printf("\n");
}