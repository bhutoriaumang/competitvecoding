#include <stdio.h>

int main(){
    int n,t,k=0,s;
    scanf("%d",&n);
    int a[n],ans[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
        
    }
    for(int i=0;i<n;i++){
        k+=a[i];
        ans[i] = 0;
    }
    scanf("%d",&t);
    s = k;
    while(k>0){
        for(int i=0;i<n;i++){
            if(a[i]==0)
                continue;
            a[i]-=t;
            k-=t;
            if(a[i]<=0){
                k-=a[i];
                a[i] = 0;
                if(ans[i]==0)
                    ans[i] = s-k;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d\n",ans[i]);
    }
}