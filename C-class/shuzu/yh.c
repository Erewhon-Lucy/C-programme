#include<stdio.h>
int main()
{
    #define N 10
    int yh[N][N] = {0};
    int i,j;

    for (i = 0; i < N; i++)
    {
        yh[i][0] = 1;
        for (j = 1; j <= i; j++)
        {
            yh[i][j] = yh[i - 1][j - 1] + yh[i - 1][j];
        }
        
    }
    for ( i = 0; i < N; i++)
    {
        for ( j = 0; j <= i; j++)
        {
            printf("%6d", yh[i][j]);    
        }
        putchar('\n');//记得放下来，如果放在上一行就变成一列了。
    }
    
    return 0;
}