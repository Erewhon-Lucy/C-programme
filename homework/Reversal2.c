# include <stdio.h>
# include <stdlib.h>

# define N 30

char *p, *q;

void reverse(char []);

int main(void)
{
    char  a[N];
    printf("Enter a message: ");

    p = a;
    q = a;
    for (; p < p+N; ++p )
    {
        *p = getchar();
        if (*p == '\n')
            break;
    }

    reverse(a);

    printf("Reversal is: ");

    for (p = a; p < q+1;++p)
    {
        printf("%c", *p);

    }

    return 0;
}

void reverse(char a[])
{
    int temp, i;
    i = p - q;
    for (; q < p; )
    {
        temp = *q;
        *q = *p;
        *p = temp;
        --p;
        ++q;
    }
    p = q = a;
    q += i;
}