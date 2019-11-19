#include<stdio.h>

void decomp(double d, int *i, double *f)
{
    *i = (int)d;//(int)强制转换
    *f = d - *i;
    //若不用指针，则只是改变副本，对实参本身无影响。
    //用指针，则通过指针改变的是实参本身。
}

int main()
{
    double x = 3.14159;
    int a =0;
    double b = 0.0;

    decomp(x, &a, &b);
    printf("%lf, %d, %lf\n", x, a, b);

    return 0;
}