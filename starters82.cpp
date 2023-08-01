#include <iostream>
using namespace std;

int calc(int a,int b,int c){
    for(int i=0;i<=1e9;i++){
        if((a*i - b)%c==0)
            return i;
    }
    return -1;
}

int main() {
	int T;
	cin>>T;
	while(T-->0){
	    int a,b,c,d;
	    cin>>a>>b>>c>>d;
	    if(a<b-1 && c<d-1){
            cout<<"1\n";
            continue;
        }
        
	}
	return 0;
}

/*

A-t = aB
C-t = cD
(A-C) = aB - cD
A-t+x = rB
C-t+x = sD

B(a-r) = D(s-c)
2x = aB+t-A + cD + t - C
2x = 0+4-4

0 : 1 2
    3 5
    5 8

    t = 2x+1 = 3y+2
    (2x-1)/3 = y
*/