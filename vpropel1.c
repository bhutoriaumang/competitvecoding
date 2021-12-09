#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int gcd(int a, int b){
    if(b==0)
        return a;
    return gcd(b,a%b);
}

int main(){
    char nn[100];
    scanf("%s",nn);
    int n = 0; 
    for(int j=0;j<strlen(nn);j++){
        if((int)nn[j]<48 || (int)nn[j]>57){
            printf("Invalid input");
            return 0;
        }
        n =n*10 + ((int)nn[j] - 48);
    }
    char aa[n][100];
    int a[n];
    for(int i=0;i<n;i++){
        a[i] = 0;
        scanf("%s",aa[i]);
        for(int j=0;j<strlen(aa[i]);j++){
            if((int)aa[i][j]<48 || (int)aa[i][j]>57){
                printf("Invalid input");
                return 0;
            }
            a[i] =a[i]*10 + ((int)aa[i][j] - 48);
        }
    }
    int x = a[0];
    for(int i=0;i<n;i++)
        x = gcd(x,a[i]);
    for(int i=0;i<n;i++){
        a[i]+=x;
        printf("%d\n",a[i]);
    }
    printf("%d",x);
}