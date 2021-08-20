#include <iostream>
using namespace std;

void input(int x[],int n){
    for(int i=0;i<n;i++){
        cout<<"Enter element "<<i+1<<" : ";
        cin>>x[i];
    }
}

void display(int *a,int n){
    int k = 0,l = 0;
    for(int i=0;i<n;i++){
        int f = 0;
        for(int j=0;j<i;j++){
            cout<<*(a+f+l)<<"\t";
            f+=(n-1)-j;
        }
        l++;
        for(int j=0;j<n-i;j++){
            cout<<*(a+k)<<"\t";
            k++;
        }
        cout<<endl;
    }
}

void display2(int *a,int n){
    for(int i=0;i<n;i++)
        cout<<*(a+i)<<endl;
}

int* multiply(int a[],int b[],int n){
    int k = 0,l = 0;
    int *c = new int(n);
    for(int i=0;i<n;i++){
        int f = 0;
        c[i] = 0;
        for(int j=0;j<i;j++){
            c[i] += (a[f+l])*b[j];
            f+=(n-1)-j;
        }
        l++;
        for(int j=0;j<n-i;j++){
            c[i] += (a[k])*b[i+j];
            k++;
        }
    }
    return c;
}

int main(){
    int n;
    cout<<"Enter the size of the matrix : ";
    cin>>n;
    int a[(n*(n+1))/2],b[n];
    cout<<endl<<endl;
    cout<<"Enter the upper right triangle of the symmetric matrix in row major form\n";
    input(a,(int)(n*(n+1))/2);
    cout<<endl<<endl;
    cout<<"The symmentric matrix is :"<<endl;
    display(a,n);
    cout<<endl<<endl;
    cout<<"Enter the vector of size "<<n<<endl;
    input(b,n);
    cout<<endl<<endl;
    cout<<"The vector is :"<<endl;
    display2(b,n);
    cout<<endl<<endl;
    int *c = multiply(a,b,n);
    cout<<"The resultant vector is :"<<endl;
    display2(c,n);
}