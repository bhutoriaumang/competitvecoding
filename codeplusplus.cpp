#include <bits/stdc++.h>
using namespace std;

int mod(string num, int a)
{
    // Initialize result
    int res = 0;
 
    // One by one process all digits of 'num'
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + (int)num[i] - '0') % a;
 
    return res;
}
int digSum(int n)
{
    int sum = 0;
    
    // Loop to do sum while
    // sum is not less than
    // or equal to 9
    while(n > 0 || sum > 9)
    {
        if(n == 0)
        {
            n = sum;
            sum = 0;
        }
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(){
    int T;
    cin>>T;
    while(T-->0){
        string n;
        int k;
        cin>>n>>k;
        int ind = -1;
        string w = n.substr(k,1);
        for(int i=k+1;i<n.length();i++){
            w+=n[i];
            if(digSum(stoi(w))==1)
                ind = i-k+1;
        }
        cout<<ind<<endl;
    }
}

/*


* x * x *
x * x * x
* x * x *
x * a * x
* x * x *


16x16
2x4

*/