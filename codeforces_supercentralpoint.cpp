#include <iostream>
using namespace std;

struct Point{
    int x,y;
};

int main(){
    int n,xmax,ymax,xmin,ymin;
    cin>>n;
    struct Point p[n];
    for(int i=0;i<n;i++){
        cin>>p[i].x>>p[i].y;
        if(i==0){
            xmax = p[i].x;
            ymax = p[i].y;
            xmin = p[i].x;
            ymin = p[i].y;
        }
        else{
            if(p[i].x>xmax)
                xmax = p[i].x;
            if(p[i].y>ymax)
                ymax = p[i].y;
            if(p[i].x<xmin)
                xmin = p[i].x;
            if(p[i].y<ymin)
                ymin = p[i].y;
        }
    }
    xmax = abs(xmax);
    xmin = abs(xmin);
    ymax = abs(ymax);
    ymin = abs(ymin);
    for(int i=0;i<n;i++){
        p[i].x+=xmin;
        p[i].y+=ymin;
    }
    int a[xmax+xmin+3][ymax+ymin+2];
    int r = xmax+xmin+1,c=ymax+ymin+1;
    for(int i=0;i<=r+1;i++){
        for(int j=0;j<=c;j++)
            a[i][j] = 0;
    }
    for(int i=0;i<n;i++){
        a[p[i].x][p[i].y] = 1;
        a[p[i].x][c]++;
        a[r][p[i].y]++;
    }
    int ans = 0;
    for(int i=0;i<r;i++){
        int count = 0;
        for(int j=0;j<c;j++){
            if(a[i][j]==0)
                continue;
            if(count>0 && (a[i][c]-count)>0 && a[r+1][j]>0 && (a[r][j]-a[r+1][j])>0){
                ans++;
            }
            a[r+1][j]++;
            count++;
        }
    }
    cout<<ans<<endl;
}