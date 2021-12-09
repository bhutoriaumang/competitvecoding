#include <stdio.h>
#include <stdlib.h>

void increment(int *aa){
    aa[2]  = 99;
}

int main(){
    char *s = (char *)malloc(100);
    scanf("%[^\n]s",s);
    printf("%s",s);
}