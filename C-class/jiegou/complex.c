#include<stdio.h>

typedef void (*FUNPTR)(int);//是指针类型，指向函数，这个函数的返回值是void,函数带有一个int型参数

// FUNPTR fp;//一个指向函数的指针
// int f(int i){//fp不能指向它
//     return 0;
// }
// void g(int i){//fp可以指向它
//     return 0;
// }

typedef struct node//node是标志名
{
    int a;
    struct node * next;
} NODE, *NODEPTR;

void traverse(NODEPTR head, FUNPTR callback)//回调函数
{
    NODEPTR p = head;
    while (p != NULL)
    {
        callback(p->a);//函数名就是指向函数的指针
        p = p->next;
    }
}

void print(int v)
{
    printf("%d\n", v);
}

void printX3(int v)
{
    printf("%d\n", v * 3);
}
int main()
{
    NODE a = {1, NULL}, b = {2, NULL}, c = {3, NULL};
    
    NODEPTR head, p;//变量类型是指针

    a.next = &b;
    b.next = &c;
    //通过next指针串在了一起，链表
    head = &a;//链表头指针 //a,b,c是节点
    traverse(head, print);
    traverse(head, printX3);

    return 0;
}