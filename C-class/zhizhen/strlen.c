#include <stdio.h>

size_t strlen(char *s)
{
    size_t i = 0;
    while (*s != '\0')
    {
        ++i;
        ++s;
    }
    return i;
}

int main()
{
    char *p = "1234567890";

    printf("%ld\n", strlen(p));

    return 0;
}