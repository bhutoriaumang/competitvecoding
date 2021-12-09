#include<stdio.h>
#include<stdlib.h>

struct patient
{
    int hNum;
    char name[40];
    int age;
    int tNum;
    int height;
    int weight;
    char reason[200];
};

int partition (struct patient *arr, int low, int high)
{
    struct patient pivot = arr[high];
    int i = (low - 1);
 
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].tNum < pivot.tNum)
        {
            i++;
            struct patient temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    struct patient temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;

    return (i + 1);
}
 
void quickSort(struct patient *arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 

int main()
{
    int n;
    printf("Enter number of patients: ");
    scanf("%d",&n);
    struct patient *p = (struct patient *)malloc(n*sizeof(struct patient));
    for(int i=0;i<n;i++)
    {
        printf("\nEnter %d patient's following details:-\n",i+1);
        printf("Enter patient's Hospital Number: ");
        scanf("%d",&p[i].hNum);
        printf("Enter patient's Name: ");
        scanf("%s", p[i].name);
        printf("Enter patient's Age: ");
        scanf("%d",&p[i].age);
        printf("Enter patient's Token Number: ");
        scanf("%d",&p[i].tNum);
        printf("Enter patient's Height: ");
        scanf("%d",&p[i].height);
        printf("Enter patient's Weight: ");
        scanf("%d",&p[i].weight);
        printf("Enter patient's Reason(Disease): ");
        scanf("%s", p[i].reason);
    }
    quickSort(p,0,n-1);

    for(int i=0;i<n;i++)
    {
        printf("%d %s\n",p[i].tNum,p[i].name);
    }
    return 0;
}