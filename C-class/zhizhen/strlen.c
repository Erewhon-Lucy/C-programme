#include <stdio.h>

size_t strlen(char *s)//计算字符串长度
{
    //算法1：
    // size_t i = 0;
    // //while (*s != '\0')
    // //while (*s)
    // while (*s++)
    // {
    //     ++i;
    //     //++s;
    // }
    // return i;

    //算法2：
    char *t = s;
    while (*t++);
    return t - s - 1;//字符串长度,循环跑到0后面去了所以t-s还要-1    
}

void strcpy(char *dest, const char *src)//复制字符串,const约束char,若要约束src 则放在src左边
{
    // while (*src)//当*src=0正好结束
    // {
    //     *dest++ = *src++;//同时完成复制和++
    //     // ++src;
    //     // ++dest;
    // }
    // *dest = '\0';//完成封尾

    //while ((*dest++ = *src++));//完成循环时，指针指到了数组外面,在外面再加上一个括号
    
    char *t = dest;
    while ((*t++ = *src++));
    return dest;//函数返回一个指针，实际上返回了一个左值对象    
}

int * foo()//反例
{
    //int i = 1;//这里的i是局部变量
    static int i = 1;//静态变量生命期更长
    return &i;//返回了一个失效单元的地址
}

int main()
{
    char *p = "1234567890";
    char *q, *t;//讨论字符串复制
    char buf[1024];//增加缓冲区

    q = buf;

    printf("%ld\n", strlen(p));
    //t = strcpy(q,p);
    *t = 'X';
    printf("%s\n", t);

    // j = foo();
    // *j = 0;
    // //*foo() = 0;也可以这么写
    // printf("%d\n", *foo());

    if ("abc" == "abc");//这么写通常不会得到真
    strcmp(p,q);//比较字符串，两字符串相等时返回0！！！！！！！！！！

    return 0;
}

//*s++等价于 t=s, ++s, 最后得到*t
