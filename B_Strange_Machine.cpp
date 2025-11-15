#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin>>T;
    while(T-->0){
        int n,q;
        cin>>n>>q;
        string s;
        cin>>s;
        vector<long long int> v(q);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        vector <int> x;
        int c = 1;
        for (int i=1;i<n;i++) {
            if (s[i] == s[i-1])
                c++;
            else {
                x.push_back(c);
                c = 1;
            }
        }
        x.push_back(c);
        for(int i=0;i<q;i++){
            int time = 0, d= (s[0]=='A') ? 0 : 1;
            while(v[i]>0) {
                if (x.size()==1 && d==0) {
                    time = v[i];
                    v[i] = 0;
                    break;
                }
                for (int j=0;j<x.size();j++) {
                    if (d==0) {
                        if (v[i] < x[j]) {
                            time += v[i];
                            v[i] = 0;
                        } else {
                            time += x[j];
                            v[i] -= x[j];
                        }
                    } else {
                        if (v[i] == 1) {
                            time++;
                            v[i] = 0;
                        }
                        else if (v[i] < pow(2,x[j])) {
                            time += floor(sqrt(v[i])) + 1;
                            v[i] = 0;
                        } else {
                            time += x[j];
                            v[i] = v[i]/pow(2,x[j]);
                        }
                    }
                    if (v[i] == 0)
                        break;
                    d = d ^ 1;
                    if (j == x.size()-1) {
                        j = -1;
                        d = (s[0]=='A') ? 0 : 1;
                    }
                }
            }
            cout<<time<<endl;
        }
    }
}

/*


A = n
B = 

1 - 1 1
2 - 2 2
3 - 3 2



*/