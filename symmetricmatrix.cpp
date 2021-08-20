#include <iostream>
using namespace std;

void input(int *a,int n){
    int x[(int)(n*(n+1))/2];
    for(int i=0;i<(int)(n*(n+1))/2;i++)
        cin>>x[i];
    int k = 0;
    for(int i=0;i<n;i++){
        for(int j=i;j<n;j++){
            *(a+i*n+j) = x[k];
            *(a+j*n+i) = x[k++];
        }
    }
}
void display(int *a,int n,int m){
    cout<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)
            cout<<*(a+i*m+j)<<"\t";
        cout<<endl;
    }
}

void inputvector(int *a,int n){
    for(int i=0;i<n;i++)
        cin>>*(a+i);
}

void multiply(int *a,int *b,int n){
    int result[n];
    for(int i=0;i<n;i++){
        result[i] = 0;
        for(int j=0;j<n;j++){
            result[i] += *(a+i*n+j)**(b+j);
        }
    }
    display(result,n,1);
}


int main(){
    cout<<"Enter the size of the given matrix";
    int n;
    cin>>n;
    int a[n][n],b[n];
    input(&a[0][0],n);
    display(&a[0][0],n,n);
    inputvector(b,n);
    display(b,n,1);
    multiply(&a[0][0],b,n);
}