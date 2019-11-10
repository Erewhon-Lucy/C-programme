#include<stdio.h>
unsigned long fact(unsigned long n)
{
    if (n <= 1)
    {
        return 1;/* code */
    }
    else
    {
        return fact(n - 1) * n;
    }
    
    // unsigned long f = 1;
    // for ( unsigned long i = 1; i <= n; i++)
    // {
    //     f *= i;
    // }
    // return f;
}
int main()
{
    unsigned long n;

    scanf("%ld", &n);
    printf("%ld", fact(n));

    return 0;
}