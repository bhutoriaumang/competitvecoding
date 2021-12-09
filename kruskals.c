#include <stdio.h>
#include <stdlib.h>

struct DSU{
    int *parent;
    int *rank;
};

void initialise(struct DSU *x,int n){
    x->parent = (int *)malloc(n * sizeof(int) );
    x->rank = (int *)malloc(n * sizeof(int) );
    for(int i=0;i<n;i++){
        x->parent[i] = -1;
        x->rank[i] = -1;
    }
}

int find(struct DSU *x , int i){
    if(x->parent[i]==-1)
        return i;
    return x->parent[i] = find(x,x->parent[i]);
}

void Unite(struct DSU *x , int a, int b){
    int s1 = find(x,a);
    int s2 = find(x,b);
    if(s1!=s2){
        if(x->rank[s1]<x->rank[s2]){
            x->parent[s1] = s2;
            x->rank[s2] += x->rank[s1];
        }
        else{
            x->parent[s2] = s1;
            x->rank[s1] += x->rank[s2];
        }
    }
}

int main(){
    int n,nn;
    scanf("%d",&nn);
    scanf("%d",&n);
    int edges[n][3];
    for(int i=0;i<n;i++){
        int a,b,c;
        scanf("%d",&a);
        scanf("%d",&b);
        scanf("%d",&c);
        edges[i][0] = c;
        edges[i][1] = a;
        edges[i][2] = b;
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(edges[j][0]>edges[j+1][0]){
                int t = edges[j][0];
                edges[j][0] = edges[j+1][0];
                edges[j+1][0] = t;
                t = edges[j][1];
                edges[j][1] = edges[j+1][1];
                edges[j+1][1] = t;
                t = edges[j][2];
                edges[j][2] = edges[j+1][2];
                edges[j+1][2] = t;
            }
        }
    }
    struct DSU v;
    initialise(&v,nn);
    int ans = 0;
    for(int i=0;i<n;i++){
        int w = edges[i][0];
        int a = edges[i][1];
        int b = edges[i][2];
        if(find(&v,a)!=find(&v,b)){
            Unite(&v,a,b);
            ans+=w;
            printf("%d %d\n",a,b);
        }
    }
    printf("%d\n",ans);
}