#include <stdio.h>

int main()
{
    int a[3][3] = {1,2,3,4,5,6,7,8,9};
    int i,j,t;
    printf("原始矩阵为：\n");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("%4d",a[i][j]);
            if (j == 2)
            printf("\n");
        }
        
    }
    printf("\n");
    printf("转置矩阵为：\n");
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            if (i > j)//不加这个是换两次
                {
                    t = a[i][j];
                    a[i][j] = a[j][i];
                    a[j][i] = t;
                }
        }
        
    }
    for ( i = 0; i < 3; i++)
    {
        for ( j = 0; j < 3; j++)
        {
            printf("%4d",a[i][j]);
            if (j == 2)
            printf("\n");
        }
        
    }
    return 0;
}