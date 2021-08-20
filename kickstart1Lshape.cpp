#include <iostream>
using namespace std;

struct element{
    int w,x,y,z;
};

int fun(int x, int y){
    int ma = x>y?x:y;
    int mi = x+y-ma;
    ma = (int)ma/2;
    ma = ma<mi?ma:mi;
    mi = (int)mi/2;
    return (ma+mi-2)>0?(ma+mi-2):0;
}

int main(){
    int t;
    cin>>t;
    for(int cas = 1;cas<=t;cas++){
        int r,c;
        cin>>r>>c;
        int a[r][c];
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++)
                cin>>a[i][j];
        }
        struct element p[r][c];
        for(int i=0;i<r;i++){
            int k=1;
            for(int j=0;j<c;j++){
                if(a[i][j]==1)
                    p[i][j].w = k++;
                else{
                    p[i][j].w = 0;
                    k = 1;
                }
            }
        }
        for(int i=0;i<r;i++){
            int k=1;
            for(int j=c-1;j>=0;j--){
                if(a[i][j]==1)
                    p[i][j].x = k++;
                else{
                    p[i][j].x = 0;
                    k = 1;
                }
            }
        }
        for(int j=0;j<c;j++){
            int k=1;
            for(int i=0;i<r;i++){
                if(a[i][j]==1)
                    p[i][j].y = k++;
                else{
                    p[i][j].y = 0;
                    k = 1;
                }
            }
        }
        for(int j=0;j<=c;j++){
            int k=1;
            for(int i=r-1;i>=0;i--){
                if(a[i][j]==1)
                    p[i][j].z = k++;
                else{
                    p[i][j].z = 0;
                    k = 1;
                }
            }
        }
        int count =0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                int left=p[i][j].w, right=p[i][j].x, up = p[i][j].y, down=p[i][j].z;
                if((left>1||right>1) && (up>1 || down>1)){
                    count+= fun(up,right)+fun(down,right)+fun(up,left)+fun(down,left);
                }
            }
        }
        cout<<"Case #"<<cas<<": "<<count<<endl;
    }
}