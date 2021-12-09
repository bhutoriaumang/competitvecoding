#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    int *a;
    int t;
    unsigned int n;
};

void push(struct Stack *s, int n){
    if(s->t == s->n){
        printf("Stack Overflow\n");
        return;
    }
    else
        s->a[++(s->t)] = n;
    return;
}

int pop(struct Stack *s){
    if(s->t == -1){
        printf("Stack Underflow\n");
        return -1;
    }
    return s->a[(s->t)--];
}

void print(struct Stack *s){
    for(int i=0;i<=s->t;i++){
        printf("%d\t",s->a[i]);
    }
    printf("\n");
}

int isFull(struct Stack *s){
    return s->t == (s->n - 1)?1:0;
}

int main(){
    struct Stack s;
    s.n = 10;
    s.t = -1;
    s.a = (int *)malloc(s.n * sizeof(int));
    while(1){
        int c;
        printf("Enter your choice: 1 to push 2 to pop 3 to print and 4 to exit\n");
        scanf("%d",&c);
        if(c==1){
            int el;
            printf("Enter element to be pushed:\n");
            scanf("%d",&el);
            push(&s,el);
        }
        else if(c==2)
            printf("%d\n",pop(&s));
        else if(c==3){
            print(&s);
        }
        else{
            print(&s);
            break;
        }
    }
}
