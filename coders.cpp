#include </Users/bits/stdc++.h>
using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;

        SinglyLinkedList() {
            this->head = nullptr;
        }

};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the insertNodeAtTail function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
SinglyLinkedListNode* insertNodeAtTail(SinglyLinkedListNode* head, int data) {
	SinglyLinkedListNode *t = head;
    while(t!=NULL){
        cout<<t->data<<"\t";
        t=t->next;
    }
    cout<<endl;
    if(head == NULL){
        SinglyLinkedListNode x(data);
        head = &x;
        head->next = NULL;
        cout<<head->data<<endl;
    }
    else{
        SinglyLinkedListNode *x = head;
        while(x->next != NULL)
            x = x->next;
        SinglyLinkedListNode temp(data);
        x->next = &temp;
        x->next->next = NULL;
    }
    SinglyLinkedListNode *x = head;
    while(x!=NULL){
        cout<<x->data<<"\t";
        x = x->next;
    }
    cout<<endl;
    cout<<"IOUBOU\n";
    return head;
}

int main()
{

    SinglyLinkedList* llist = new SinglyLinkedList();

    int llist_count;
    cin >> llist_count;

  
    for (int i = 0; i < llist_count; i++) {
        int llist_item;
        cin >> llist_item;

    	SinglyLinkedListNode* llist_head = insertNodeAtTail(llist->head, llist_item);
      	llist->head = llist_head;
    }


    print_singly_linked_list(llist->head, "\n");

    free_singly_linked_list(llist->head);

    return 0;
}
