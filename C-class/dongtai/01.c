#include<stdio.h>
#include<stdlib.h>

int main()
{
    int a;
    int *p, *q;
    //void * malloc的原始返回类型
    q = p = (int *)malloc(sizeof(int));//malloc，生成动态内存分配，大小为int大小
    *p = 1;//把1放到指针P指向的内存，生存期非常长，在程序结束也不会消失

    free(p);//动态内存的释放，和malloc是一对
    *q = 2;

    return 0;
}