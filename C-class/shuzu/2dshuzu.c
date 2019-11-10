#include<stdio.h>

int main()
{
    #define M 3
    #define N 5
    #define K 3
    int a[M][N] = {
        1,2,3,4,5,
        2,3,4,5,6,
        3,4,5,6,7
    },
    b[N][K] = {
        3,4,5,
        4,5,6,
        5,6,7,
        6,7,8,
        8,9,0
    },
    c[M][K] = {0};
    int i, j, k;
   for ( i = 1; i <= M; ++i)
   {
      for ( j = 1; j < K; ++j)
      {
        int sum = 0;
        for ( k = 1; k < N; ++k)
        {
           sum += a[i][k]*b[k][j];
           c[i][j] = sum;
        }
        
        a[i - 1][j - 1] = i * j;
      }
       
   }
    for ( i = 0; i < N; ++i)
    {
        for ( j = 0; j < N; ++j)
            printf("%6d",a[i][j]);
        putchar('\n');
    }

return 0;
}