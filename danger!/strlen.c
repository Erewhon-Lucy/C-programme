#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char x[] = "STRING";
    x[0] = 0;
    x[1] = '\0';
    x[2] = '0';
    printf("%d %d\n", sizeof(x),strlen(x));
    return 0;
}