#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int n,*a,r,f;
};
void enqueue(struct Queue *p){
    int k;
    printf("Enter the element:\n");
    scanf("%d",&k);
    if((p->r == (p->n - 1) && p->f==-1) || (p->r==p->f && p->r!=-1))
        printf("Queue full!\n");
    else{
        p->r++;
        p->r = p->r%p->n;
        p->a[p->r] = k;
    }
}

void display(struct Queue *p){
    if(p->r!=-1){
        for(int i=p->f+1;i!=p->r;i=((i+1)%(p->n)))
            printf("%d ",p->a[i%(p->n)]);
        printf("%d\n",p->a[p->r]);
    }
    else
        printf("Empty queue\n");
}

void dequeue(struct Queue *p){
    if(p->r == -1)
        printf("Queue is empty!\n");
    else{
        p->f++;
        p->f%=p->n;
        printf("%d\n",p->a[p->f]);
        if(p->f == p->r){
            p->f = -1;
            p->r = -1;
        }
    }
}

int main(){
    struct Queue l;
    printf("Enter the size of the queue\n");
    scanf("%d",&l.n);
    l.r = -1;
    l.f = -1;
    l.a = (int *)malloc(4*l.n);
    while(1){
        printf("Enter 1 to enter element 2 to dequeue element 3 to display and 4 to exit\n");
        int i;
        scanf("%d",&i);
        if(i==1)
            enqueue(&l);
        else if(i==2)
            dequeue(&l);
        else if(i==3)
            display(&l);
        else
            break;
    }
}