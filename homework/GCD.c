#include<stdio.h>
int main()
{
    int a,b;
    int t;

    printf("Enter two integers: ");
    scanf("%d %d",&a,&b);
    
    while ( b!=0 )
    {
        t = a % b;
        a = b;
        b = t;/* code */
    }
    printf("Greatest common divisor: %d\n",a);
    

    return 0;
}