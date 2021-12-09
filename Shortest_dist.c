#include <stdio.h>
#include <math.h>

int count=0;

struct Point{
    double x;
    double y;
};

double dist(struct Point p1 , struct Point p2){
    count++;
    return (double)sqrt(pow((p1.x - p2.x),2) + pow((p1.y-p2.y),2));
}

void input(struct Point p[] ,int n){
    for(int i=0;i<n;i++){
        printf("Enter a point:\n");
        scanf("%lf",&p[i].x);
        scanf("%lf",&p[i].y);
    }
}

void print(struct Point p[], int n){
    for(int i=0;i<n;i++){
        printf("Point %d is : (%.2lf, %.2lf)\n",i+1,p[i].x,p[i].y);
    }
}

void calculate(struct Point p[], int n){
    double min = INFINITY;
    struct Point p1,p2;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            double d = dist(p[i],p[j]);
            if(d<min){
                min = d;
                p1 = p[i];
                p2 = p[j];    
            }
        }
    }
    printf("%.2lf is the shortest pair difference and its between the points ( %lf , %lf ) and ( %lf , %lf )\n",min,p1.x,p1.y,p2.x,p2.y);
}

void equal_ycord(struct Point p[],int n){
    double min = INFINITY;
    struct Point p1,p2;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(fabs(p[i].x-p[j].x)<min){
                min = fabs(p[i].x - p[j].x);
                p1 = p[i];
                p2 = p[j];
            }
        }
    }
    printf("%.2lf is the shortest pair difference and its between the points ( %lf , %lf ) and ( %lf , %lf )\n",fabs(p1.x - p2.x),p1.x,p1.y,p2.x,p2.y);
}

void input2(struct Point p[],int n){
    int b;
    printf("Enter the common y-coordinate b:\n");
    scanf("%d",&b);
    for(int i=0;i<n;i++){
        printf("Enter the x-coordinate of point %d :\n",i+1);
        scanf("%lf",&p[i].x);
        p[i].y = b;
    }
}

int main(){
    int n,b;
    printf("Enter the number of points : ");
    scanf("%d",&n);
    struct Point pts[n];
    printf("Enter 1 for coordinates with equal y-coordinate and 2 for unequal y-coordinates : ");
    scanf("%d",&b);
    if(b==1){
        input2(pts,n);
        print(pts,n);
        equal_ycord(pts,n);
    }
    else{
        input(pts,n);
        print(pts,n);
        calculate(pts,n);
        printf("\nNumber of times the Eucledian distance is calculated is : %d",count);
    }
    printf("\n");
    return 0;
}