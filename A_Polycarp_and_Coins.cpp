/*

Problem Tags: ['greedy', 'math'] 

*/

#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        long long int n;
        cin>>n;
        long long int c1,c2;
        int k = n%3;
        c1 = n/3;
        c2 = c1;
        if(k==1)
            c1+=1;
        else if(k==2)
            c2+=1;
        cout<<c1<<" "<<c2<<endl;
    }
}