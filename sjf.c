#include <stdio.h>

int main(){
    int n,c;
    scanf("%d %d",&n,&c);
    int bur[n],arr[n],wt[n],tt[n],ct[n];
    for(int i=0;i<n;i++){
        arr[i] = 0;
        if(c){
            printf("Enter the arrival time of process %d\t:\t",(i+1));
            scanf("%d",&arr[i]);
        }
    }
    for(int i=0;i<n;i++){
        printf("Enter the burst time of process %d\t:\t",(i+1));
        scanf("%d",&bur[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1] || (arr[j]==arr[j+1] && bur[j]>bur[j+1])){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                temp = bur[j];
                bur[j] = bur[j+1];
                bur[j+1] = temp;
            }
        }
    }
    int sum = arr[0],k=0;
    for(int t=0;t<n;t++){
        int kk = k;
        while(kk<n && arr[kk]<=sum){
            kk++;
        }
        int minimum = k;
        for(int i=k;i<kk;i++){
            if(bur[minimum]>bur[i]){
                minimum = i;
            }
        }
        int temp = arr[k];
        arr[k] = arr[minimum];
        arr[minimum] = temp;
        temp = bur[k];
        bur[k] = bur[minimum];
        bur[minimum] = temp;
        sum+=bur[k];
        ct[k] = sum;
        k++;
    }
    int ttt=0,twt=0;
    printf("Process_Number\tArrival_Time\tBurst_Time\tWaiting_Time\tTurnaround_Time\tCompletion_Time\n\n");
    for(int i=0;i<n;i++){
        tt[i] = ct[i] - arr[i];
        wt[i] = tt[i] - bur[i];
        ttt += tt[i];
        twt += wt[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",(i+1),arr[i],bur[i],wt[i],tt[i],ct[i]);
    }
    printf("Average waiting time = %.4lf\n",((double)twt/(double)n));
    printf("Average turnaround time = %.4lf\n",((double)ttt/(double)n));
}