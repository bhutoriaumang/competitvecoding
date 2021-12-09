#include <unistd.h> 
#include <stdio.h>
#include <sys/wait.h>

int main(){
    int n,c;
    scanf("%d %d",&n,&c);
    int arr[n],bur[n],wt[n],tt[n];
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
    int sum = 0,twt=0,ttt=0;
    printf("Process_Number\tWaiting_Time\tTurnaround_Time\n\n");
    for(int i=0;i<n;i++){
        if(arr[i]>sum)
            sum = arr[i];
        sum+=bur[i];
        tt[i] = sum - arr[i];
        wt[i] = tt[i] - bur[i];
        ttt += tt[i];
        twt += wt[i];
        printf("%d\t\t%d\t\t%d\n",(i+1),wt[i],tt[i]);
    }
    printf("Average waiting time = %.4lf\n",((double)twt/(double)n));
    printf("Average turnaround time = %.4lf\n",((double)ttt/(double)n));
}