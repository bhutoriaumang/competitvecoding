#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

struct Queue {
    int front, rear, size;
    unsigned capacity;
    int* array;
};

struct Queue* createQueue(unsigned capacity)
{
    struct Queue* queue = (struct Queue*)malloc(
        sizeof(struct Queue));
    queue->capacity = capacity;
    queue->front = queue->size = 0;
    queue->rear = capacity - 1;
    queue->array = (int*)malloc(
        queue->capacity * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue)
{
    return (queue->size == queue->capacity);
}

int isEmpty(struct Queue* queue)
{
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item)
{
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1)
                  % queue->capacity;
    queue->array[queue->rear] = item;
    queue->size = queue->size + 1;
}

int dequeue(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1)
                   % queue->capacity;
    queue->size = queue->size - 1;
    return item;
}
 
int front(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->front];
}

int rear(struct Queue* queue)
{
    if (isEmpty(queue))
        return INT_MIN;
    return queue->array[queue->rear];
}

void display(struct Queue q){
    printf("Queue\t:\t");
    while(!isEmpty(&q)){
        printf("%d\t",dequeue(&q));
    }
    printf("\n\n");
}

int main(){
    int n,c;
    scanf("%d %d",&n,&c);
    int arr[n],bur[n],wt[n],tt[n],ct[n],burcpy[n];
    for(int i=0;i<n;i++){
        arr[i] = 0;
        if(c){
            printf("Enter the arrival time of process %d\t:\t",(i+1));
            scanf("%d",&arr[i]);
        }
    }
    for(int i=0;i<n;i++){
        printf("Enter the burst time of process %d\t:\t",(i+1));
        scanf("%d",&bur[i]);
        burcpy[i] = bur[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                temp = bur[j];
                bur[j] = bur[j+1];
                bur[j+1] = temp;
                temp = burcpy[j];
                burcpy[j] = burcpy[j+1];
                burcpy[j+1] = temp;
            }
        }
    }
    int tq,s=arr[0],k=1;
    printf("Time Quantum\t:\t");
    scanf("%d",&tq);
    struct Queue* q = createQueue(n);
    enqueue(q,0);
    while(!isEmpty(q)){
        s+=tq;
        int p = tq;
        while(k<n && arr[k]<=s){
            enqueue(q,k);
            k++;
        }
        while(p>0){
            if(isEmpty(q))
                break;
            int t = dequeue(q);
            if(p<bur[t]){
                bur[t]-=p;
                p = 0;
                enqueue(q,t);
            }
            else{
                ct[t] = s-p+bur[t];
                p-=bur[t];
                bur[t]=0;
            }
        }
    }
    int sum = 0,twt=0,ttt=0;
    printf("Process_Number\tArrival_Time\tBurst_Time\tWaiting_Time\tTurnaround_Time\tCompletion_Time\n\n");
    for(int i=0;i<n;i++){
        tt[i] = ct[i] - arr[i];
        wt[i] = tt[i] - burcpy[i];
        ttt += tt[i];
        twt += wt[i];
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",(i+1),arr[i],burcpy[i],wt[i],tt[i],ct[i]);
    }
    printf("Average waiting time = %.4lf\n",((double)twt/(double)n));
    printf("Average turnaround time = %.4lf\n",((double)ttt/(double)n));
}