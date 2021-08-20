#include <iostream>
using namespace std;

struct Stack
{
    int *a;
    int t;
    unsigned int n;
};

void push(struct Stack *s, int n){
    if(s->t == s->n){
        cout<<"Stack Overflow\n";
        return;
    }
    else
        s->a[++(s->t)] = n;
    return;
}

int pop(struct Stack *s){
    if(s->t == -1){
        cout<<"Stack Underflow\n";
        return -1;
    }
    return s->a[(s->t)--];
}

void print(struct Stack *s){
    for(int i=0;i<=s->t;i++){
        cout<<s->a[i]<<"\t";
    }
    cout<<endl;
}

int isFull(struct Stack *s){
    return s->t == (s->n - 1)?1:0;
}

int main(){
    struct Stack s;
    s.n = 10;
    s.t = -1;
    s.a = new int(s.n*sizeof(int));
    while(1){
        int c;
        cout<<("Enter your choice: 1 to push 2 to pop 3 to print and 4 to exit\n");
        cin>>c;
        if(c==1){
            int el;
            cout<<("Enter element to be pushed:\n");
            cin>>el;
            push(&s,el);
        }
        else if(c==2)
            cout<<pop(&s)<<endl;
        else if(c==3){
            print(&s);
        }
        else{
            print(&s);
            break;
        }
    }
}