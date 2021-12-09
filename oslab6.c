#include <stdio.h>

int main(){
    int n,l,x=-1,k=0,t=-1;
    printf("Size of the frame\n");
    scanf("%d",&n);
    printf("Length of the reference string\n");
    scanf("%d",&l);
    int a[l],v[n];
    printf("Reference string\n");
    for(int i=0;i<l;i++)
        scanf("%d",&a[i]);
    for(int i=0;i<n;i++)
        v[i] = -1000000;
    for(int i=0;i<l;i++){
        if(v[n-1]==-1000000){
            k++;
            t++;
            v[t] = a[i];
        }
        else{
            int found = -1;
            for(int j=0;j<n;j++){
                if(a[i]==v[j]){
                    found = j;
                    break;
                }
            }
            if(found==-1){
                k++;
                found = 0;
            }
            for(int j=found;j<n-1;j++){
                v[j] = v[j+1];
            }
            v[n-1]=a[i];
        }
    }
    printf("Page faults\n");
    printf("%d\n",k);
}