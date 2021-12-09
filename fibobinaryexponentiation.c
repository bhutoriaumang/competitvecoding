#include <stdio.h>

struct matrix
{
    int a, b, c, d;
};

struct matrix fibo(struct matrix xx, int n)
{
    if (n == 1)
        return xx;
    struct matrix p,x;
    if(n%2==0)
        x = fibo(xx, n / 2);
    else
        x = fibo(xx,n-1);
    if (n % 2)
    {
        p.a = x.a * xx.a + x.b * xx.c;
        p.b = x.a * xx.b + x.b * xx.d;
        p.c = x.c * xx.a + x.d * xx.c;
        p.d = x.c * xx.b + x.d * xx.d;
        return p;
    }
    p.a = x.a * x.a + x.b * x.c;
    p.b = x.a * x.b + x.b * x.d;
    p.c = x.c * x.a + x.d * x.c;
    p.d = x.c * x.b + x.d * x.d;
    return p;
}

int main()
{
    struct matrix i, r;
    i.a = 0;
    i.b = 1;
    i.c = 1;
    i.d = 1;
    r = fibo(i, 8);
    printf("%d %d", r.c, r.d);
}