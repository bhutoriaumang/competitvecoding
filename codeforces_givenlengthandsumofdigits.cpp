#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t-->0){
        int x,y,a,b,n,m;
        cin>>n>>m;
        cin>>x>>y;
        cin>>a>>b;
        int dp,dt;
        dp = min((n-a),(m-b));
        a+=dp;
        b+=dp;
        dp+=max((n-a),(m-b));
        dt = (n-x)+(m-y);
        if(dp>=dt)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
	return 0;
}


/*

    1   1   1   0   0   0   0   1   1
    1   1   0   0   1   1   1   0   0
    1   0   1   1   1   0   1   0   1
    0   0   1   0   0   0   1   0   0


    3   2   1   0   0   0   0   2   1
    2   1   0   0   3   2   1   0   0
    1   0   3   2   1   0   1   0   1
    0   0   1   0   0   0   1   0   0


*/