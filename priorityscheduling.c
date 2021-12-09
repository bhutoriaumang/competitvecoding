#include <stdio.h>

int main(){
    int n,c;
    scanf("%d %d",&n,&c);
    int arr[n],bur[n],burcpy[n],wt[n],tt[n],ct[n],pri[n];
    for(int i=0;i<n;i++){
        arr[i] = 0;
        ct[i] = -1;
        if(c){
            printf("Enter the arrival time of process %d\t:\t",(i+1));
            scanf("%d",&arr[i]);
        }
    }
    for(int i=0;i<n;i++){
        printf("Enter the burst time of process %d\t:\t",(i+1));
        scanf("%d",&bur[i]);
        burcpy[i] = bur[i];
    }
    for(int i=0;i<n;i++){
        printf("Enter the priority of process %d\t:\t",(i+1));
        scanf("%d",&pri[i]);
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
                temp = burcpy[j];
                burcpy[j] = burcpy[j+1];
                burcpy[j+1] = temp;
                temp = pri[j];
                pri[j] = pri[j+1];
                pri[j+1] = temp;
            }
        }
    }
    int l[n],ll=1;
    l[0] = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1])
            continue;
        l[ll++] = arr[i];
    }
    int k = 0,s=0;
    for(int ind=0;ind<ll;ind++){
        int kk = k;
        while(kk<n && arr[kk]<=l[ind])
            kk++;
        for(int i=0;i<kk-1;i++){
            for(int j=0;j<kk-1-i;j++){
                if(pri[j]>pri[j+1]){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    temp = bur[j];
                    bur[j] = bur[j+1];
                    bur[j+1] = temp;
                    temp = burcpy[j];
                    burcpy[j] = burcpy[j+1];
                    burcpy[j+1] = temp;
                    temp = pri[j];
                    pri[j] = pri[j+1];
                    pri[j+1] = temp;
                }
            }
        }
        if(ind!=(ll-1)){
            int p = l[ind+1]-l[ind];
            for(int i=k;i<kk;i++){
                if(bur[i]<=p){
                    ct[i] = l[ind] + bur[i];
                    p-=bur[i];
                    bur[i] = 0;
                    k++;
                }
                else{
                    bur[i]-=p;
                    p = 0;
                }
            }
        }
    }
    s = l[ll-1];
    for(int i = k;i<n;i++){
        ct[i] = s+bur[i];
        s+=bur[i];
        bur[i] = 0;
    }
    int sum = 0,twt=0,ttt=0;
    printf("Process_Number\tArrival_Time\tBurst_Time\tWaiting_Time\tTurnaround_Time\tCompletion_Time\n\n");
    for(int i=0;i<n;i++){
        tt[i] = ct[i] - arr[i];
        wt[i] = tt[i] - burcpy[i];
        ttt += tt[i];
        twt += wt[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",(i+1),arr[i],burcpy[i],wt[i],tt[i],ct[i]);
    }
    printf("Average waiting time = %.4lf\n",((double)twt/(double)n));
    printf("Average turnaround time = %.4lf\n",((double)ttt/(double)n));
}