#include <stdio.h>
#include <string.h>

char ans[100][100];
int count = 0;


struct Node{
    struct Node *l,*r,*p;
    int v,ind,f;
};

int minind(struct Node x[],int n){
    int m = -1;
    for(int i=0;i<n;i++){
        if(x[i].f == 0)
            continue;
        if(m==-1 || x[m].v >= x[i].v)
            m = i;
    }
    return m;
}

void calc(struct Node *x,char str[]){ 
    if(x->l == NULL && x->r==NULL){
        strcpy(ans[x->ind],str);
        return;
    }
    if(x->l != NULL){
        char t = '0';
        char temp[1000];
        strcpy(temp,str);
        strncat(temp,&t,1);
        calc(x->l,temp);
    }
    if(x->r !=NULL){
        char t = '1';
        char temp[1000];
        strcpy(temp,str);
        strncat(temp,&t,1);
        calc(x->r,temp);
    }
}

int main(){
    int n;
    scanf("%d",&n);
    struct Node x[n+n];
    for(int i=0;i<n;i++){
        int t;
        scanf("%d",&t);
        x[i].v = t;
        x[i].ind = i;
        x[i].f = 1;
        x[i].l = NULL;
        x[i].r = NULL;
    }
    
    int l = 0;
    while(l<n-1){
        int index = minind(x,n+l);
        struct Node w;
        x[index].f = 0;
        w.v = x[index].v;
        w.l = &x[index];
        w.f = 1;
        index = minind(x,n+l);
        x[index].f = 0;
        w.v += x[index].v;
        w.r = &x[index];
        x[n+l] = w;
        l++;
    }
    char temp[1000];
    calc(&x[n+l-1],temp);
    for(int i=0;i<n;i++)
        printf("%s ",ans[i]);
    printf("\n");
}