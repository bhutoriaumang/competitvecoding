#include <iostream>
using namespace std;

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int x,y,n,m;
        cin>>n>>m;
        cout<<n;
        cout<<m;
        for(x=0;x<=n;x++)
        {
            cout<<"hello";
            y=m-x;
            if(n%x==0 && n%y==0)
            {
                if(x<y)
                {
                    cout<<"YES"<<endl;
                }
                else
                {
                    cout<<"NO"<<endl;
                }
            }
            else
            {
                cout<<"NO"<<endl;
            }
            y=0;
        }
    }

    return 0;
}
