#include <iostream>
using namespace std;

int main(){
    cout << "Enter the number of processes : ";
    int n;
    cin>>n;
    int arr[n],bur[n],burcpy[n],wt[n],tt[n],ct[n],pno[n];
    for(int i=0;i<n;i++){
        cout << "Enter arrival time for process "<<(i+1)<<"\n";
        cin>>arr[i];
        cout << "Enter burst time for process "<<(i+1)<<"\n";
        cin>>bur[i];
        burcpy[i] = bur[i];
        ct[i] = -1;
        pno[i] = i+1;
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
                temp = pno[j];
                pno[j] = pno[j+1];
                pno[j+1] = temp;
            }
        }
    }
    int l[n],ll=1;
    for(int i=1;i<n;i++){
        if(arr[i]==arr[i-1])
            continue;
        l[ll++] = arr[i];
    }
    int k=0,s=0;
    for(int ind=0;ind<ll;ind++){
        int kk=k;
        while(kk<n && arr[kk]<=l[ind])
            kk++;
        for(int i=0;i<kk-1;i++){
            for(int j=0;j<kk-i-1;j++){
                if(bur[j]>bur[j+1] || (bur[j]==bur[j+1] && arr[j]>arr[j+1])){
                    int temp = arr[j];
                    arr[j] = arr[j+1];
                    arr[j+1] = temp;
                    temp = bur[j];
                    bur[j] = bur[j+1];
                    bur[j+1] = temp;
                    temp = burcpy[j];
                    burcpy[j] = burcpy[j+1];
                    burcpy[j+1] = temp;
                    temp = pno[j];
                    pno[j] = pno[j+1];
                    pno[j+1] = temp;
                }
            }
        }
        if(ind!=(ll-1)){
            int p = l[ind+1] - l[ind];
            for(int i=k;i<kk;i++){
                if(bur[i]<=p){
                    ct[i] = l[ind] + bur[i];
                    p-=bur[i];
                    bur[i]=0;
                    k++;
                }
                else{
                    bur[i]-=p;
                    p=0;
                }
            }
        }
    }
    s = l[ll-1];
    for(int i=k;i<n;i++){
        ct[i] = s+bur[i];
        s+=bur[i];
        bur[i]=0;
    }
    int sum=0,twt=0,ttt=0;
    for(int i=0;i<n;i++){
        tt[i] = ct[i]-arr[i];
        wt[i] = tt[i]-burcpy[i];
        ttt+=tt[i];
        twt+=wt[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(pno[j]>pno[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                temp = bur[j];
                bur[j] = bur[j+1];
                bur[j+1] = temp;
                temp = burcpy[j];
                burcpy[j] = burcpy[j+1];
                burcpy[j+1] = temp;
                temp = pno[j];
                pno[j] = pno[j+1];
                pno[j+1] = temp;
            }
        }
    }
    cout<<"Execution order of processes from Gantt chart : "<<endl<<endl;
    for(int i=0;i<n;i++){
        cout<<"Waiting time of process "<<pno[i]<<" is "<<wt[i]<<endl;
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"Turnaround time of process "<<pno[i]<<" is "<<tt[i]<<endl;
    }
    cout<<endl;
    cout << "Average Waiting Time = " << ((double)twt/(double)n) <<endl;
    cout << "Average Turnaround Time = " << ((double)ttt/(double)n) <<endl;
}