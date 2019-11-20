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

    while ((*dest++ = *src++));//完成循环时，指针指到了数组外面,在外面再加上一个括号
    
}

int main()
{
    char *p = "1234567890";
    char *q;//讨论字符串复制
    char buf[1024];//增加缓冲区

    q = buf;

    printf("%ld\n", strlen(p));
    strcpy(q,p);
    printf("%s\n", q);

    return 0;
}

//*s++等价于 t=s, ++s, 最后得到*t