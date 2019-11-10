#include<stdio.h>
int main()
{
    int x;
    int i;

    scanf("%d", &x);
    for ( i = 2; i < x; i++)
    {
        if (x % i == 0)
        {
            printf("不是素数\n");
           break;
        }
        
    }
    if ( i == x )
    {
        printf("是素数\n");
    }
    return 0;
}