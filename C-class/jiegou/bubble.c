#include <stdio.h>

#define N   10

void bubble_sort(int a[], int len)
{
    int i, j;

    for (i = 0; i < len - 1; ++i)
        for (j = 0; j < len - i - 1; ++j)
            if (a[j] >= a[j+1])
            { // block
                int t = a[j];
                a[j] = a[j+1];
                a[j+1] = t;
            }
}

void print_array(int a[], int len, int w)
{
    int i;
    for (i = 0; i < len; ++i)
        printf("%*d", w, a[i]);
    putchar('\n');
}

int main()
{
    //array
    int a[N] = {3, 5, 2, 1, 4, 9, 7, 6, 0, 8};
    int b[5] = {77, 66, 99, 33, 22};

    // algorithm
    bubble_sort(a, N);
    print_array(a, N, 4);

    bubble_sort(b, 5);
    print_array(b, 5, 6);

    return 0;
}