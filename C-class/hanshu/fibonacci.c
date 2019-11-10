#include<stdio.h>
long fibonacci(long n)
{
    if(n == 1 || n == 2)
    return 1;
    else
    {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }
    //若int fibonacci(long n, long a, long b)
    //return n <= 2 ? 1 : fibonacci(n - 1) + fibonacci(n - 2);
    //return n == 1 ? a : fibonacci(n - 1, b, a + b);
}
int main()
{
    long n = 0;
    long x;
    printf("n=");
    scanf("%ld", &n);
	x = fibonacci(n);
	printf("x=%ld", x);
	return 0;

}