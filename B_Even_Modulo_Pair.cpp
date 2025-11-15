#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T-->0){
        int n,o=-1,e=-1;
        cin >> n;
        vector <int> v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        int f = 1;
        for(int i=1;i<n;i++){
            if ((v[i]%v[0])%2==0) {
                cout << v[0] << " " << v[i] << endl;
                f = 0;
                break;
            }
        }
        if (f) {
            cout << "-1" << endl;
        }
    }
}

/*

x y z

y%x = y - t1x
z%x = z - t2x
z%y = z - t3y

z%x+t2x = z%y+t3y


15 28 123

13 3


*/