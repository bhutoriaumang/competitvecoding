// #include </Users/bits/stdc++.h>
// using namespace std;
// #define lli long long int

// /*

// The time complexity to find nth fibonacci element using recursive method is O(2^n) (with some assumtions) , thus the method has exponential time complexity.

// */

// lli recursive(lli n){   //Function to find the nth fibonacci number using recursion
//     if(n==0)
//         return 0;
//     else if(n==2 || n==1)
//         return 1;
//     return recursive(n-1) + recursive(n-2);
// }

// /*

// The time complexity to find the nth fibonacci number using iterative method is O(n)

// */

// lli iterative(lli n){   //Function to find the nth fibonacci number using iteration method
//     if(n==0)
//         return 0;
//     else if(n==2 || n==1)
//         return 1;
//     lli a=0,b=1,c;
//     n-=2;
//     while(n>=0){
//         c = a+b;
//         n--;
//         a = b;
//         b = c;
//     }
//     return b;
// }

// double computePower(double x , lli n){    //Computing the power of golden ration using divide and conquer method
//     if(n==1)
//         return x;
//     else if(n%2==0){
//         double y = computePower(x,n/2);
//         return y*y;
//     }
//     else{
//         double y = computePower(x,(n-1)/2);
//         return y*y*x;
//     }
// }

// /*

// The time complexity to compute Binet's idea is O(log n) as we use a divide and conquer approach to calculate the value of (phi^n). The issues of implementing Binet's idea is the usage of irrational numbers as there is no way to represent irrational numbers in programs but to substitute it with its actual value which could end up causing some slight error due to some missing decimal places.

// */

// lli Binets(lli n){  //Function to find the nth fibonacci number using Binet's idea
//     if(n==0)
//         return 0;
//     else if(n==2 || n==1)
//         return 1;
//     return round(computePower((1+sqrt(5))/2,n)/sqrt(5));
// }

// vector<vector <lli> > Knuths(vector <vector <lli> > a , int n){ //Function to find the nth fibonacci number using Knuth's formula
//     if(n==1)
//         return a;
//     if(n%2==0){
//         a = Knuths(a,n/2);
//         int A = a[0][0]*a[0][0];
//         int B = a[0][1]*a[0][1];
//         int C = a[1][1]*a[1][1];
//         a[0][0] = A+B;
//         a[0][1] = A-C;
//         a[1][0] = A-C;
//         a[1][1] = C+B;
//         return a;
//     }
//     else{
//         vector < vector <lli> > b = Knuths(a,(n-1)/2);
//         int A = b[0][0]*b[0][0];
//         int B = b[0][1]*b[0][1];
//         int C = b[1][1]*b[1][1];
//         b[0][0] = A+B;
//         b[0][1] = A-C;
//         b[1][0] = A-C;
//         b[1][1] = C+B;
//         vector <vector <lli> > c = a;
//         c[0][0] = b[0][0]*a[0][0] + b[0][1]*a[1][0];
//         c[0][1] = b[0][0]*a[0][1] + b[0][1]*a[1][1];
//         c[1][0] = b[1][0]*a[0][0] + b[1][1]*a[1][0];
//         c[1][1] = b[1][0]*a[0][1] + b[1][1]*a[1][1];
//         return c;
//     }
// }

// int main(){
//     lli n;
//     cout<<"Enter the term number which we need to find : ";
//     cin>>n;
//     vector < vector <lli> > a;
//     vector <lli> temp(2,1);
//     a.push_back(temp);
//     a.push_back(temp);
//     a[1][1] = 0;
//     cout<<"Using recursive : "<<recursive(n)<<endl;
//     cout<<"Using iterative : "<<iterative(n)<<endl;
//     cout<<"Using Binet's idea : "<<Binets(n)<<endl;
//     cout<<"Using Knuth's formula : "<<Knuths(a,n)[0][1]<<endl;
// }

#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

//Method 1: Recursive Method
int recursive(int n)
{
    if(n<=1)
    {
        return n;
    }
    return recursive(n-1) + recursive(n-2);
}

//Method 2: Iterative Method
int iterative(int n)
{
    int a=0,b=1,c;
    if(n==0)
    {
        return 0;
    }
    for(int i=2;i<=n;i++)
    {
        c = a + b;
        a=b;
        b=c;
    }
    return b;
}

//Method 3: Using Binet's formula
int binet(int n)
{
    double phi = (1+sqrt(5)) / 2;
    return round(pow(phi,n)/sqrt(5));
}

//knuth
vector<vector<int> > Knuth(vector<vector<int> > mat1, int n)
{
    if (n == 1)
        return mat1;
    if (n % 2 == 0)
    {
        mat1 = Knuth(mat1, n / 2);
        mat1[0][0] = mat1[0][0] * mat1[0][0] + mat1[0][1] * mat1[0][1];
        mat1[0][1] = mat1[0][0] * mat1[0][0] - mat1[1][1] * mat1[1][1];
        mat1[1][0] = mat1[0][0] * mat1[0][0] - mat1[1][1] * mat1[1][1];
        mat1[1][1] = mat1[1][1] * mat1[1][1] + mat1[0][1] * mat1[0][1];
        return mat1;
    }
    else
    {
        vector<vector<int> > mat2 = Knuth(mat1, (n - 1) / 2);
        mat2[0][0] = mat2[0][0] * mat2[0][0] + mat2[0][1] * mat2[0][1];
        mat2[0][1] = mat2[0][0] * mat2[0][0] - mat2[1][1] * mat2[1][1];
        mat2[1][0] = mat2[0][0] * mat2[0][0] - mat2[1][1] * mat2[1][1];
        mat2[1][1] = mat2[1][1] * mat2[1][1] + mat2[0][1] * mat2[0][1];
        vector<vector<int> > mat3 = mat1;
        mat3[0][0] = mat2[0][0] * mat1[0][0] + mat2[0][1] * mat1[1][0];
        mat3[0][1] = mat2[0][0] * mat1[0][1] + mat2[0][1] * mat1[1][1];
        mat3[1][0] = mat2[1][0] * mat1[0][0] + mat2[1][1] * mat1[1][0];
        mat3[1][1] = mat2[1][0] * mat1[0][1] + mat2[1][1] * mat1[1][1];
        return mat3;
    }
}

int main()
{
    int n;
    vector < vector <int> > a;
    vector <int> temp(2,1);
    a.push_back(temp);
    a.push_back(temp);
    a[1][1] = 0;
    cout<<"Enter n: ";
    cin>>n;
    if(n>0)
    {
        cout<<"The Fn value using recursive method is "<<recursive(n)<<endl;
        cout<<"The Fn value using iterative method is "<<iterative(n)<<endl;
        cout<<"The Fn value using binet's method is "<<binet(n)<<endl;
        cout<<"The Fn value using knuth method is "<<Knuth(a,n)[0][1]<<endl;
    }
    else
    {
        cout<<"Invalid value of n!!!";
        exit(0);
    }
    return 0;
}