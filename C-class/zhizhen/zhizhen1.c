#include<stdio.h>

int main()
{
    // char i = 1, j;
    // char *p = &i，*q = &j;

    // p + (p - q) / 2;

    // printf("%p, %p\n", p, p + 3);
    
    int a[] = {1,2,3,4,5};
    //变量a的类型是int [5]
    int *p;
    //变量p的类型是 int *

    //p = &a[0];
    //p指向了数组的首元素
    //若写成 p = &a[5] ,其实没有错，因为一定有这个地址，
    //但如果之后写了*p = 6 ;则有错，因为单元无效，则不能访问这个地址

    p = a;
    //和p = &a[0]; 等价，若倒过来则不行，数组是常量指针,他们具有相同的基类型
    // p[i] === a[i]
    // a + i === &a[i]
    //*(a + i ) === a[i]
    // *(p + i) === *(a + i)
    // p + i === a + i
    // a[i] === *(i +a) === i[a]
    int i;
    // for (p = a + 4; p >= a; --p){
    //     printf("%4d", *p);
    //     //指针的移动
    // } 

    for (p = a + 4; p > a; --p){
        *p = *(p - 1);
        printf("%4d", *p);
        //指针的移动
    }
    *p = 0;   
    putchar('\n');
    return 0;
}