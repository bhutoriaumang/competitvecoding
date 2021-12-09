#include<stdio.h>
int main()
{
  int n,m,c=0,d=0;
  scanf("%d %d",&n,&m);
  char a[n][m];
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      scanf(" %c",&a[i][j]);
    }
  }
  for(int j=0;j<m-1;j++)
  {
    for(int i=0;i<n-1;i++)
    {
      int z=i;
      if(a[z][j]==a[z+1][j])
      {
        while(a[z][j]==a[z+1][j])
        {
          c=1;
          z+=1;
          printf("\nc:%d z:%d",c,z);
        }
        if(c==1)
        {
          if(a[z][j]==a[z][j+1])
          {
            d=1;
            printf("\nd:%d\n",d);
          }
        }
      }
      c=0;
    }
  }
  if(d==1)
  {
    printf("Yes");
  }
  else
  {
    printf("No");
  }
  return 0;
}