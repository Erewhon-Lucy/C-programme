#include<stdio.h>

int main()
{
    // char a[] = {'a', 'b', 'c', '\0'};
    //char b[] = "abc";
    char b[1024];
    char *p;//若不对指针进行初始化，就是野指针，对野指针的使用一定会出错
    
    p = b;
    //b[0] = 'A';
    //*p = 'A';
    
    //scanf("%s", p);
    //gets(p);
    fgets(p, 1023, stdin);//从stdin（标准输入文件）中读入数据, p是指针
    fputs(p, stderr);

    printf("%s\n", p);//s%在编译器眼里是字符串的地址

    return 0;
}