#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    int v[3];
    int k=0,fa=0;
    for(int i=0;i<3;i++){
        v[i] = -1;
    }
    for(int i=0;i<n;i++){
        printf("%d\n",arr[i]);
        if(k<3){
            int f = 0;
            for(int j=0;j<3;j++){
                if(v[j]==arr[i])
                    f = 1;
            }
            if(f==1){
                fa++;
                continue;
            }
            v[k] = arr[i];
            k++;
        }
        else{
            int f = 0;
            for(int j=0;j<3;j++){
                if(v[j]==arr[i])
                    f = 1;
            }
            if(f==0){
                printf("YEs\n");
                int c[3];
                fa--;
                c[0] = 0;
                c[1] = 0;
                c[2] = 0;
                for(int j=i-3;j<=(i+3);j++){
                    if(v[0]==arr[j])
                        c[0]++;
                    if(v[1]==arr[j])
                        c[1]++;
                    if(v[2]==arr[j])
                        c[2]++;
                }
                int m = 0;
                if(c[m]>c[1])
                    m = 1;
                if(c[m]>c[2])
                    m = 2;
            }
            else
                fa++;
        }
        for(int j=0;j<3;j++)
            printf("%d ",v[j]);
        printf("\t:\t%d\t\n",fa);
    }
    printf("%d\n",fa);
}