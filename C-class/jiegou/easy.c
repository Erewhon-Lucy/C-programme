#include<stdio.h>

typedef struct 
{
    int a;
    char c;
} foo;

int main()
{
    foo x = {
        1, 'A'
    };
    foo *p = &x; //指针指向结构体

    printf("%d,%c\n", p->a, p->c);
    
    return 0;
}
