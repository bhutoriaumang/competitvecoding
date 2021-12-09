#include <stdio.h>

int main(){
    int s,n,x;
    scanf("%d",&s);
    scanf("%d",&x);
    scanf("%d",&n);
    int v[n];
    for(int i=0;i<n;i++)
        scanf("%d",&v[i]);
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(v[j]<v[j+1]){
                int t = v[j];
                v[j] = v[j+1];
                v[j+1] = t;
            }
        }
    }
    int t = -1;
    for(int i=0;i<n;i++){
        if(x<v[i])
            t++;
    }
    int sum = 0,xx=x;
    for(int i=t;i>=0;i--){
        sum+= -(x-v[i]);
        x = v[i];
    }
    t++;
    for(int i=t;i<n;i++){
        sum+=-(v[i]-x);
        x = v[i];
    }
    sum+= v[n-1]+1-v[0]+s;
    printf("%d",sum);
}