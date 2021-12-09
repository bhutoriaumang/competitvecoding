#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node{
    struct Node *l,*r,*p;
    int data;
};

struct Node* CreateNode(int t);
struct Node* AddNode(struct Node *k , int t);
void preorder(struct Node *k);

struct Node *head = NULL;
int comparisons = 0;

struct Node* CreateNode(int t){
    struct Node *k = (struct Node *)malloc(sizeof(struct Node));
    k->data = t;
    k->l = NULL;
    k->r = NULL;
    k->p = NULL;
    return k;
}

struct Node* AddNode(struct Node *k,int t){
    if(k==NULL){
        k = CreateNode(t);
        return k;
    }
    if(t<=k->data){
        k->l = AddNode(k->l,t);
        k->l->p = k;
        printf("%d Left : %d\n",k->data,k->l->data);
    }
    else{
        k->r = AddNode(k->r,t);
        k->r->p = k;
        printf("%d Right : %d\n",k->data,k->r->data);
    }
    return k;
}

void preorder(struct Node *k){
    if(k!=NULL){
        printf("%d\t",k->data);
        preorder(k->l);
        preorder(k->r);
    }
    if(k==head)
        printf("\n");
}

void postorder(struct Node *k){
    if(k!=NULL){
        postorder(k->l);
        postorder(k->r);
        printf("%d\t",k->data);
    }
    if(k==head)
        printf("\n");
}

void inorder(struct Node *k){
    if(k!=NULL){
        inorder(k->l);
        printf("%d\t",k->data);
        inorder(k->r);
    }
    if(k==head)
        printf("\n");
}

int searchNode(struct Node *k,int t){
    if(k==NULL)
        return -1;
    if(k->data==t)
        return 1;
    else if(t<k->data)
        return searchNode(k->l,t);
    else
        return searchNode(k->r,t);
}

int minNode(struct Node *k){
    if(k->l==NULL)
        return k->data;
    return minNode(k->l);
}

int maxNode(struct Node *k){
    if(k->r==NULL)
        return k->data;
    return maxNode(k->r);
}

int size(struct Node *k){
    if(k==NULL)
        return 0;
    return 1+size(k->l)+size(k->r);
}

void kthmax(struct Node *k,int t, int *count){
    if(t==*count)
        return;
    if(k!=NULL){
        kthmax(k->r,t,count);
        (*count)++;
        if(t==*count)
            printf("The %d th maximum is : %d\n",t,k->data);
        kthmax(k->l,t,count);
    }
}

int succesor(struct Node *k){
    if(k->r!=NULL)
        return minNode(k->r);
    else{
        struct Node *temp = k->p;
        while(temp!=NULL && temp->r==k){
            k = temp;
            temp = temp->p;
        }
        if(temp==NULL)
            return -1;
        return temp->data;
    }
}

int predecessor(struct Node *k){
    if(k->l!=NULL)
        return maxNode(k->l);
    else{
        struct Node *temp = k->p;
        while(temp!=NULL && temp->l==k){
            k = temp;
            temp = temp->p;
        }
        if(temp==NULL)
            return -1;
        return temp->data;
    }
}

void deleteNode(struct Node *node,int k){
	if(node==NULL){
		printf("No such element present\n");
	}
	else if(node->data>k){
		deleteNode(node->l,k);
	}
	else if(node->data<k){
		deleteNode(node->r,k);
	}
	else{
		if(node->l==NULL && node->r==NULL){
			if(node->p->l==node){
				free(node);
				node->p->l=NULL;
			}
			else if(node->p->r==node){
				free(node);
				node->p->r=NULL;
			}
			printf("Element deleted\n");
		}
		else if(node->l==NULL || node->r==NULL){
			if(node->l == NULL){
				node->data = node->r->data;
				deleteNode(node->r,node->r->data);
			}
			else{
				node->data = node->l->data;
				deleteNode(node->l,node->l->data);
			}
		}
		else{
			int temp = succesor(node);
			node->data = temp;
			deleteNode(node->r,temp);
		}
	}
}

struct Node* construct_from_preorder(int a[],int len){
    int l[len],r[len],parent = a[0];
    int lc=0,rc=0;
    for(int i=1;i<len;i++){
        if(a[i]<parent)
            l[lc++] = a[i];
        else
            r[rc++] = a[i];
    }
    struct Node *parentNode = (struct Node*)malloc(sizeof(struct Node));
    parentNode->data = parent;
    if(lc>0)
        parentNode->l = construct_from_preorder(l,lc);
    else
        parentNode->l = NULL;
    if(rc>0)
        parentNode->r = construct_from_preorder(r,rc);
    else
        parentNode->r = NULL;
    return parentNode;
}

int height(struct Node *node, int c){
    comparisons++;
    if(node==NULL)
        return c-1;
    int l = height(node->l,c+1);
    int r = height(node->r,c+1);
    return (l>r)?l:r;
}

int findLevel(struct Node *x, int val){
    if(x==NULL)
        return -1000;
    if(x->data==val)
        return 1;
    int l = findLevel(x->l,val);
    int r = findLevel(x->r,val);
    return 1 + ((l>r)?l:r);
}

int main(){
    int c = 0,count =0;
    while(c!=-1){
        printf("Enter 1 to add new node\nEnter 2 to search for an element\nEnter 3 to display tree\nEnter 4 to print size of the tree\nEnter 5 to print minimum element and the maximum element of the tree\nEnter 6 to print the kth max\nEnter 7 to delete a node\nEnter -1 to exit\n> ");
        scanf("%d",&c);
        if(c==1){
            int t;
            printf("Enter element to be added : ");
            scanf("%d",&t);
            head = AddNode(head,t);
            head->p = NULL;
        }
        else if(c==2){
            int t;
            printf("Enter element to be searched : ");
            scanf("%d",&t);
            searchNode(head,t);
            printf("The succesor is : %d\n",succesor(head->l));
        }
        else if(c==3){
            printf("Preorder : ");
            preorder(head);
            printf("Inorder : ");
			inorder(head);
            printf("Postorder : ");
			postorder(head);
        }
        else if(c==4)
            printf("Size of the Tree is : %d\n",size(head));
        else if(c==5){
            printf("Minimum element of the Tree is : %d\n",minNode(head));
            printf("Maximum element of the Tree is : %d\n",maxNode(head));
		}
        else if(c==6){
            count = 0;
            int t;
            printf("Enter the value of k : ");
            scanf("%d",&t);
            kthmax(head,t,&count);
        }
		else if(c==7){
			int t;
            printf("Enter element to be deleted : ");
            scanf("%d",&t);
            deleteNode(head,t);
		}
        else if(c==8){
            int n;
            scanf("%d",&n);
            int s[n];
            for(int i=0;i<n;i++)
                scanf("%d",&s[i]);
            struct Node *root = construct_from_preorder(s,n);
            preorder(root);
            inorder(root);
            postorder(root);
        }
        else if(c==9){
            printf("Height of the tree is: %d in %d comparisons\n",height(head,1),comparisons);
        }
        else if(c==10){
            int val;
            printf("Enter the value of the node: ");
            scanf("%d",&val);
            printf("The node is at level : %d\n",findLevel(head,val));
        }
        else if(c!=-1){
            printf("Incorrect option\n");
        }
    }
}