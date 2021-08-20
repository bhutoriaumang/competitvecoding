#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,k,s[n];
        cin >> n;
        cin >> k;
        int count=0,index;
        cout << "Enter the elements:" << endl;
        for(int i=0;i<n;i++)
            cin >> s[i];
        int temp = 0;
        for(int i=0;i<n;i++){
            if(s[i]==0)
                temp++;
            else{
                if(count < temp){
                    index = i;
                    count = temp;
                }
                temp = 0;
            }
        }
        cout<<count<<" "<<index;
    }
}