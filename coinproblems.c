#include <stdio.h>

int main(){
    int n,P;
    //Taking input from User
    printf("Enter the amount to find change for\t:\t");
    scanf("%d",&P);
    printf("Enter the number of denominations\t:\t");
    scanf("%d",&n);
    int a[n];
    for(int i=0;i<n;i++){
        printf("Enter denomination %d\t:\t",(i+1));
        scanf("%d",&a[i]);
    }
    //Sorting the array using bubble sort
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]<a[j+1]){
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
        }
    }
    int c = 0,k=0;
    //Calculating the minimum change required
    while(P>0){
        printf("Coins for denomination %d used are : %d\n",a[k],(P/a[k]));
        c+=(P/a[k]);
        P = P%a[k];
        k++;
    }
    printf("Total coins used\t:\t%d\n",c);
}