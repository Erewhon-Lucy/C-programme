#include<stdio.h>
double average(double x, double y)
{
    double t = (x + y) / 2.0;
    x = y = 0;
    return t;   //别忘了这个
}

int main()
{
    double a, b, c;
    a = 2.3, b = 4.6;
    c = average(a , b);

    return 0;   //停-等模式
}