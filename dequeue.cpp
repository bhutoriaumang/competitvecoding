#include <iostream>
using namespace std;

struct Dequeue{
    int *a;
    int f,r,n;
};

int isFull(struct Dequeue *t){
    if(t->r == (t->n-1) && t->f==0)
        return 1;
    return 0;
}

int isEmpty(struct Dequeue *t){
    if(t->f==-1 && t->r==-1)
        return 1;
    return 0;
}

void AddFront(struct Dequeue *t,int x){
    if(isFull(t)==1){
        cout<<"Queue is full"<<endl;
    }
    else if(isEmpty(t)){
        t->f++;
        t->r++;
        *(t->a) = x;
    }
    else if(t->f==0){
        t->f = t->n-1;
        *(t->a + t->f) = x;
    }
    else{
        t->f--;
        *(t->a + t->f) = x;
    }
}

void AddLast(struct Dequeue *t, int x){
    if(isFull(t)==1){
        cout<<"Queue is full"<<endl;
    }
    else if(isEmpty(t)){
        t->f++;
        t->r++;
        *(t->a) = x;
    }
    else if(t->r==(t->n - 1)){
        t->r = 0;
        *(t->a + t->r) = x;
    }
    else{
        t->r++;
        *(t->a + t->r) = x;
    }
}

int DelFirst(struct Dequeue *t){
    int x;
    if(isEmpty(t)){
        x = -1;
    }
    else if(t->f==t->r){
        x = *(t->a + t->f);
        t->f = -1;
        t->r = -1;
    }
    else if(t->f == (t->n - 1)){
        x = *(t->a + t->f);
        t->f = 0;
    }
    else{
        x = *(t->a + t->f);
        t->f++;
    }
    return x;
}

int DelLast(struct Dequeue *t){
    int x;
    if(isEmpty(t)){
        x = -1;
    }
    else if(t->f==t->r){
        x = *(t->a + t->f);
        t->f = -1;
        t->r = -1;
    }
    else if(t->r == 0){
        x = *(t->a + t->r);
        t->r = t->n - 1;
    }
    else{
        x = *(t->a + t->r);
        t->r--;
    }
    return x;
}

void display(struct Dequeue *t){
    if(isEmpty(t)==1){
        cout<<"The queue is empty"<<endl;
        return;
    }
    for(int i=t->f;i!=t->r;i = (i+1)%(t->n)){
        cout<<*(t->a + i)<<"\t";
    }
    cout<<*(t->a + t->r)<<endl;
}

int main(){
    struct Dequeue t;
    cout<<"Enter size of the queue : ";
    cin>>t.n;
    cout<<endl<<endl;
    t.a = (int *)malloc(t.n*sizeof(int));
    t.f = -1;
    t.r = -1;
    int c = -1;
    while(1){
        cout<<"Enter 1 to add element at front\nEnter 2 to add element at last\nEnter 3 to delete element form front\nEnter 4 to delete element from last\nEnter 5 to display queue\nEnter any other number to exit\n";
        cout<<endl<<endl;
        cout<<"Enter the choice : ";
        cin>>c;
        if(c==1){
            int x;
            cout<<"Enter the element to enter : ";
            cin>>x;
            cout<<endl<<endl;
            AddFront(&t,x);
        }
        else if(c==2){
            int x;
            cout<<"Enter the element to enter : ";
            cin>>x;
            cout<<endl<<endl;
            AddLast(&t,x);
        }
        else if(c==3){
            int x = DelFirst(&t);
            if(x!=-1)
                cout<<"Deleted Element is : "<<x<<endl;
            else
                cout<<"No elements to delete"<<endl;
            cout<<endl<<endl;
        }
        else if(c==4){
            int x = DelLast(&t);
            if(x!=-1)
                cout<<"Deleted Element is : "<<x<<endl;
            else
                cout<<"No elements to delete"<<endl;
            cout<<endl<<endl;
        }
        else if(c==5){
            display(&t);
            cout<<endl<<endl;
        }
        else{
            display(&t);
            break;
        }
    }
}