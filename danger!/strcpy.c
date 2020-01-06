#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char a[20] = "ABCD\0EFG\0", b[] = "IJK";
    strcat(a,b);
    printf("%s\n",a);
    return 0;
}