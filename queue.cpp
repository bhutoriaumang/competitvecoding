#include <iostream>
using namespace std;

struct Queue{
    int n,*a,r,f;
};
void enqueue(struct Queue *p){
    int k;
    cout<<("Enter the element:\n");
    cin>>k;
    if(p->r == (p->n - 1))
        cout<<("Queue full!\n");
    else{
        p->a[++p->r] = k;
    }
}

void display(struct Queue *p){
    for(int i=p->f+1;i<=p->r;i++)
        cout<<p->a[i]<<" ";
    cout<<endl;
}

void dequeue(struct Queue *p){
    if(p->f == p->r)
        cout<<("Queue is empty!\n");
    else{
        cout<<p->a[++p->f]<<endl;
        if(p->f == p->r){
            p->f = -1;
            p->r = -1;
        }
    }
}

int main(){
    struct Queue l;
    cout<<("Enter the size of the queue\n");
    cin>>l.n;
    l.r = -1;
    l.f = -1;
    l.a = new int(sizeof(int)*l.n);
    while(1){
        cout<<("Enter 1 to enter element 2 to dequeue element 3 to display and 4 to exit\n");
        int i;
        cin>>i;
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