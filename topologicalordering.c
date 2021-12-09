#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,e;
    scanf("%d",&n);
    scanf("%d",&e);
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            a[i][j] = 0;
    }
    for(int i=0;i<e;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        a[x][y] = 1;
    }
    int v[n],vis[n];
    int k = 0;
    for(int i=0;i<n;i++)
        vis[i] = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==0)
                continue;
            if(vis[j]==1)
                continue;
            v[k++] = j;
            vis[j] = 1;
        }
        if(vis[i]==0)
            v[k++] = i;
        vis[i] = 1;
    }
    while(k>0){
        k--;
        printf("%d ",v[k]);
    }
    printf("\n");
}