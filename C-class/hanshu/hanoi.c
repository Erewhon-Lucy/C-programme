#include<stdio.h>
//hanoi(n, src, dest, aux)
//hanoi(n, a, b, c)
//  hanoi(n-1, a, c, b)
//  a -> b
//  hanoi(n-1, c, b, a)
void hanoi(int n, char src, char dest, char aux)
{
    if (n == 1)
    {
        printf("%c-->%c\n", src, dest);
        return;
    }
    
    hanoi(n-1, src, aux, dest);
    printf("%c-->%c\n", src, dest);
    hanoi(n - 1, aux, dest, src);
}

int main()
{
    int n = 3;
    hanoi(n, 'a', 'b', 'c');
    return 0;
}