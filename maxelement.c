#include <stdio.h>
#include <math.h>

int comparisons = 0;

int max(int a[],int s,int e){
    comparisons++;
    if(s==e){
        return s;
    }
    else if(e-s==1){
        return (a[s]>a[e])?s:e;
    }
    else if(s<e){
        int m = (s+e)/2;
        int x = max(a,s,m);
        int y = max(a,m+1,e);
        return (a[x]>a[y])?x:y;
    }
    return INFINITY;
}

int main(){
    int n;
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    printf("Position: %d\tComparisons: %d",max(a,0,n-1),comparisons);
}