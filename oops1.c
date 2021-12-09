#include <stdio.h>
#include <stdlib.h>

void update(int *a){
    for(int i=0;i<3;i++){
        *(a+i) += 5;
    }
}

void display(int *a){
    for(int i=0;i<3;i++)
        printf("%d\t",*(a+i));
    printf("\n");
}

int main(){
    int *a;
    a = (int *)malloc(3*sizeof(int));//100
    for(int i=0;i<3;i++){
        scanf("%d",a+i);
    }
    return 0;
}

/*
    100 104 108


*/