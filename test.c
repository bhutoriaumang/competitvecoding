#include <stdio.h>
#include <string.h>

char ans[100][100];

int main(){
    char x[] = "ABCD";
    strcpy(ans[0],x);
    printf("%s",ans[0]);
}