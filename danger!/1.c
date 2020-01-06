#include <stdio.h>
#include <math.h>

void main()
{
    float s=1,t=1,i=3;
    do
    {
        t = -t*(i-1)*i;
        s = s+1/t;
        i+=2;
    } while (fabs(1/t)>=1e-5);
    printf("%.4f\n",s);
}