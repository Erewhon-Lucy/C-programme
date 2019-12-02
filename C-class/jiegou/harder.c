#include<stdio.h>

typedef struct 
{
    int a;
    char *c;//指针作为结构成员
} foo, *fooPTR;//结构指针类型

void boo(foo y)//结构作为函数参数，无效修改
{
    y.a = 2;
    y.c ="Banana";
}

void goo(fooPTR y)//指针作为函数参数，可
{
    y->a = 2;
    y->c ="Hamburger";
}

int main()
{
    foo x = {
        1, "ABC"
    };
    fooPTR p = &x; //等价于foo *p = &x//不可以fooPTR *p,这个等价于foo **p//指向指针的指针

    boo(x);//传这个无用
    goo(p);//传地址有用
    printf("%d,%s\n", p->a, p->c);
    
    return 0;
}