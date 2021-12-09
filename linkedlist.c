#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
}; 

struct node * addStart(struct node *head, int a) {
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->value = a;
    if (head==NULL) {
        printf("UMANG");
        head = (struct node*)malloc(sizeof(struct node));
        head->value = a;
        head->next = NULL;
        temp = head;
    }
    else {
        printf("umang");
        temp->next = head;
        head = temp;
    }
    return temp;
}

void addEnd(struct node *head, int a) {
    struct node *temp, *r;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->value = a;
    if(head==NULL) {
        head = temp;
        head->next = NULL;
    }
    else {
        r = head;
        while(r->next!=NULL) {
            r = r->next;
        }
        r->next = temp;
        temp->next = NULL;
    }
}

void addPosition(struct node *head, int a, int pos) {
    struct node *temp, *m, *n;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->value = a;
    for(int i=0;i<pos-1;i++) {
        m=n;  //used to get the node before n after step 53
        if(n->next==NULL){
            break;
        }
        else {
            n=n->next;
        }
    }
    if(m==NULL) { //implying empty linked list
        head=temp;
        head->next=NULL;
    }
    else {
        struct node *ptr=m->next;
        m->next = temp;
        temp->next = ptr;
    }
}

void display(struct node *head) {
    struct node *r;
    r=head;
    while(r!=NULL)
    {
        printf("%d ",r->value);
        r=r->next;
    }
}

void add(struct node *head, int a) {
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->value = a;
}


int main(){
    struct node *l1;
    l1 = addStart(l1,5);
    display(l1);
    return 0;
}