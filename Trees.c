#include <stdio.h>
#include <stdlib.h>

struct node{
    int data,x;
    struct node *next;
};

void create(struct node *head){
    head = (struct node *)malloc(1*sizeof(struct node));
    printf("Enter the parent node");
    scanf("%d",&head->data);
    printf("Enter the number of child node");
    scanf("%d",&head->x);
}

int main(){
    return 0;
}