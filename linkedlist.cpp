#include <iostream>
#include <stdlib.h>
using namespace std;

struct node
{
    int val,status;
    struct node *link;
};

struct node *head,*lastdeleted;

void addStart(int t);
void addMiddle(int t);
void addLast(int t);
int delStart();
int delMiddle();
int delLast();
void display();
int size();

int size(){
    struct node *temp;
    temp = head;
    int n = 0;
    while(temp->link!=NULL){  
        if(temp->status==1){
            n++;
        }
        temp = temp->link;
    }
    return n;
}

void addStart(int t){
    if(head==NULL){
        head->val = t;
        head->status = 1;
        head->link = NULL;
    }
    else{
        struct node *temp;
        temp = head;
        head = (struct node *)malloc(sizeof(struct node));
        head->link = temp;
        head->val = t;  
        head->status = 1;  
    }
}

void addMiddle(int t){
    struct node *temp;
    temp = head;
    int i;
    cout<<("Enter a position: ");
    cin>>i;
    if(i==0){
        addStart(t);
        return;
    }
    while(temp!=NULL && (i)>1){
        if(temp->status==1)
            i--;
        temp = temp->link;
    }
    if(i>1){
        cout<<("Invalid position, enter again\n");
        addMiddle(t);
    }
    struct node *x;
    x = (struct node *)malloc(sizeof(struct node));
    x->val = t;
    x->status = 1;
    x->link = temp->link;
    temp->link = x;
}

void addLast(int t)
{
    struct node *temp;
    temp = head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->val = t;
    temp->status = 1;
    temp->link = (struct node *)malloc(sizeof(struct node));
}

int delStart(){
    if(size()==0){
        cout<<("No nodes to delete\n");
        return -1;
    }
    struct node *temp = head;
    while(temp->status==0)
        temp=temp->link;
    temp->status = 0;
    lastdeleted = temp;
    int i = 0;
    return temp->val;
}

int delMiddle(){
    if(size()==0){
        cout<<("No nodes to delete\n");
        return -1;
    }
    int i;
    cout<<("Enter a position: ");
    cin>>i;
    if(i==0)
        return delStart();
    struct node *temp = head;
    while(temp!=NULL && (i)>1){
        if(temp->status==1)
            i--;
        temp = temp->link;
    }
    if(i>1){
        cout<<("Invalid position, enter again\n");
        return delMiddle();
    }
    temp->link->status = 0;
    lastdeleted = temp->link;
    return temp->link->val;
}

int delLast(){
    if(size()==0){
        cout<<("No nodes to delete\n");
        return -1;
    }
    struct node *temp,*last;
    temp = head;
    while (temp->link != NULL)
    {
        if(temp->status==1)
            last = temp;
        temp = temp->link;
    }
    last->status = 0;
    lastdeleted = last;
    return last->val;
}

void display()
{
    struct node *temp = head;
    while (temp->link != 0)
    {
        if(temp->status==1)
            cout<<temp->val<<"->";
        temp = temp->link;
    }
    cout<<("NULL\n");
}

void recall(struct node *deleted[], int *index){
    for(int i=0;i<*index;i++)
        cout<<deleted[i]->val<<"\t";
    cout<<endl;
    deleted[*index-1]->status = 1;
    *(index) = *index - 1;
    display();
}

void deleteall(){
    struct node *temp,*temp2;
    if(head==NULL){
        temp = head;
        head = head->link;
        free(temp);
        if(head==NULL)
            return;
    }
    temp2 = head;
    while(temp2->link!=NULL){
        if(temp2->link->status==0){
            temp = temp2->link;
            temp2->link = temp2->link->link;
            free(temp);
            if(temp2->link==NULL)
                return;
        }
        temp2 = temp2->link;
    }
}

int main()
{
    head = (struct node *)malloc(sizeof(struct node));
    lastdeleted = (struct node *)malloc(sizeof(struct node));
    lastdeleted = NULL;
    struct node *deleted[1000];
    int index = 0;
    while (1)
    {
        cout<<("\n\nEnter 1 to add element\nEnter 2 to delete an element\nEnter 3 to display all elements\nEnter 4 to display size of the list\nEnter 5 to print the value of last deleted node\nEnter any other number to exit\n> ");
        int c;
        cin>>c;
        cout<<("\n\n");
        if(size()<index){
            deleteall();
            index = 0;
        }
        if (c == 1)
        {
            int el,c;
            cout<<("Enter an element:\n");
            cin>>el;
            cout<<("Press 1 to enter at start\nPress 2 to enter at an index i\nPress 3 to enter at last\nEnter the choice : ");
            cin>>c;
            if(c==1)
                addStart(el);
            else if(c==2)
                addMiddle(el);
            else if(c==3)
                addLast(el);
            else
                cout<<("Invalid Choice\n");
        }
        else if(c==2){
            int c;
            cout<<("Press 1 to delete at start\nPress 2 to delete at an index i\nPress 3 to delete at last\nEnter the choice : ");
            cin>>c;
            if(c==1){
                cout<<"Element deleted : "<<delStart()<<endl;
                deleted[index++] = lastdeleted;
            }
            else if(c==2){
                cout<<"Element deleted : "<<delMiddle()<<endl;
                deleted[index++] = lastdeleted;
            }
            else if(c==3){
                cout<<"Element deleted : "<<delLast()<<endl;
                deleted[index++] = lastdeleted;
            }
            else
                cout<<("Invalid Choice\n");
        }
        else if (c == 3)
            display();
        else if (c == 4)
            cout<<"Size of the list is : "<<size()<<endl;
        else if (c == 5){
            if(index!=0)
                recall(deleted,&index);
            else
                cout<<("No elements deleted yet\n");
        }
        else
        {
            display();
            break;
        }
    }
}