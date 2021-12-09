#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node *next;
    struct node *prev;
};

struct linkedlist{
    struct node *head;
    struct node *tail;
};

void addLast(struct linkedlist*l,int t);
void addMiddle(struct linkedlist*l,int t);
void addStart(struct linkedlist*l,int t);
int delStart(struct linkedlist *l);
int delMiddle(struct linkedlist *l);
int delLast(struct linkedlist *l);

void addStart(struct linkedlist *l, int t){
    if(l->head == NULL){
        l->head = (struct node *)malloc(sizeof(struct node));
        l->head->val = t;
        l->head->prev = NULL;
        l->head->next = NULL;
        l->tail = l->head;
        return;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->next = l->head;
    temp->prev = NULL;
    temp->val = t;
    l->head->prev = temp;
    l->head = temp;
}

void addMiddle(struct linkedlist *l , int t){
    int p;
    printf("Enter the position to add the node: ");
    scanf("%d",&p);
    if(p==1 || l->head==NULL)
        addStart(l,t);
    else{
        struct node *temp = l->head;
        while(temp!=NULL && (p--)>1)
            temp = temp->next;
        if(p<0 || p>1){
            printf("Invalid position, Enter again\n");
            addMiddle(l,t);
            return;
        }
        if(temp==NULL){
            addLast(l,t);
            return;
        }
        struct node *x = (struct node *)malloc(sizeof(struct node));
        x->val = t;
        temp->prev->next = x;
        x->next = temp;
        x->prev = temp->prev;
        temp->prev = x;
    }
}

void addLast(struct linkedlist *l, int t){
    if(l->head == NULL){
        l->head = (struct node *)malloc(sizeof(struct node));
        l->head->val = t;
        l->head->prev = NULL;
        l->head->next = NULL;
        l->tail = l->head;
        return;
    }
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->val = t;
    l->tail->next = temp;
    temp->prev = l->tail;
    temp->next = NULL;
    l->tail = temp;
}

int delStart(struct linkedlist *l){
    if(l->head==NULL){
        printf("No nodes to delete\n");
        return -1;
    }
    if(l->head == l->tail){
        struct node *x = l->head;
        int t = l->head->val;
        l->head = NULL;
        l->tail = NULL;
        free(x);
        return t;
    }
    struct node *x = l->head;
    x->next->prev = NULL;
    int t = l->head->val;
    l->head = l->head->next;
    free(x);
    return t;
}

int delMiddle(struct linkedlist *l){
    int p;
    printf("Enter the position to delete the node: ");
    scanf("%d",&p);
    if(p==1 || l->head==NULL)
        return delStart(l);
    else{
        struct node *temp = l->head;
        while(temp!=NULL && (p--)>1)
            temp = temp->next;
        if(p<0 || p>=1){
            printf("Invalid position, Enter again\n");
            return delMiddle(l);
        }
        if(temp==l->tail){
            return delLast(l);
        }
        struct node *x = temp;
        int t = temp->val;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(x);
        return t;
    }
}

int delLast(struct linkedlist *l){
    if(l->head==NULL){
        printf("No nodes to delete\n");
        return -1;
    }
    if(l->head == l->tail){
        struct node *x = l->head;
        int t = l->head->val;
        l->head = NULL;
        l->tail = NULL;
        free(x);
        return t;
    }
    struct node *x = l->tail;
    int t = l->tail->val;
    l->tail->prev->next = NULL;
    l->tail = l->tail->prev;
    free(x);
    return t;
}

void display(struct linkedlist *l){
    struct node *temp = l->head;
    while(temp!=NULL)
    {
        printf("%d -> ",temp->val);
        temp = temp->next;
    }
    printf("NULL\n");
    
}

int main(){
    struct linkedlist l;
    while (1)
    {
        printf("Enter 1 to add element 2 to display elements and 3 to delete and any other number to exit: ");
        int c;
        scanf("%d", &c);
        if (c == 1)
        {
            int el,c;
            printf("Enter an element:\n");
            scanf("%d", &el);
            printf("Press 1 to enter at start\nPress 2 to enter at an index i\nPress 3 to enter at last\nEnter the choice: ");
            scanf("%d",&c);
            if(c==1)
                addStart(&l,el);
            else if(c==2)
                addMiddle(&l,el);
            else if(c==3)
                addLast(&l,el);
            else
                printf("Invalid Choice");
        }
        else if (c == 2)
            display(&l);
        else if(c==3){
            printf("Press 1 to enter at start\nPress 2 to enter at an index i\nPress 3 to enter at last\nEnter the choice: ");
            scanf("%d",&c);
            if(c==1)
                delStart(&l);
            else if(c==2)
                delMiddle(&l);
            else if(c==3)
                delLast(&l);
            else
                printf("Invalid Choice");
        }
        else
        {
            display(&l);
            break;
        }
    }
}