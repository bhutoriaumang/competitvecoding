#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define int long long

void solve()
{
  int n,m,k;
  cin>>n>>m>>k;

  vector <pair<int,int>> a;

  for(int i=0;i<n*m;i++)
  {
    int x,y;
    cin>>x>>y;

    x--;
    y--;

    a.push_back({x,y});
  }

  int l=0,r=n*m-1,ans=n*m;

  for(int mid=0;mid<n*m;mid++)
  {
    int arr[n][m];
    memset(arr,0,sizeof(arr));

    for(int i=0;i<=mid;i++)
    {
      if(i%2==0)
        arr[a[i].first][a[i].second]=1;
      else
        arr[a[i].first][a[i].second]=-1;
    }

    int flag=0;

    for(int i=0;i<n;i++)
    {
      for(int j=0;j<m;j++)
      {
        if(i+k-1<n && j+k-1<m)
        {
          int temp=0;
          for(int itr=0;itr<k;itr++)
          {
            for(int ptr=0;ptr<k;ptr++)
              temp+=arr[i+itr][j+ptr];
          }

          if(abs(temp)==k*k)
          {
            flag=1;
            break;
          }
        }
      }

      if(flag)
        break;
    }


    if(flag)
    {
      ans=mid;
      break;
    }
  }

  if(ans==n*m)
    cout<<"Draw"<<"\n";
  else if(ans%2)
    cout<<"Bob"<<"\n";
  else
    cout<<"Alice"<<"\n";
}

int32_t main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  int t;
  cin>>t;

  while(t--)
    solve();

return 0;
}