#include<stdio.h>
int main()
{
    int x, y, z;
    for ( x = 0; x < 20; x++)
    {
        for ( y = 0; y < 33; y++)
        {
            for ( z = 0; z < 100; z++)
            {
                if (x * 15 + y * 9 + z * 1 == 300 && x + y + z == 100)
                {
                    printf("%d个公鸡，%d个母鸡，%d个小鸡。\n", x, y, z);
                }
                
            }
            
        }
        
    }
    return 0;
}