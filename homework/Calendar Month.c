#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, n, start;

    printf("Enter number of days in month:");
    scanf("%d",&n);
    printf("Enter starting day of the week(1=Sun, 7=Sat):");
    scanf("%d",&start);

    for ( i = 1; i < start; i++)
    {
      printf("   ");
    }
    for ( i = 1; i <= n; i++)
    {
      printf("%3d",i);
      if ((start + i - 1) % 7 == 0)
      {
          printf("\n");
      }
      
    }
    printf("\n");
    return 0;
}