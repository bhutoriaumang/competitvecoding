#include <iostream>
using namespace std;

template <class T> T compare(T a, T b){
    return (a>b)?a:b;
}

int main(){
    cout<<compare(1,4)<<endl;
    cout<<compare(1.42,0.4)<<endl;
    cout<<compare('a','r')<<endl;
}