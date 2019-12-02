#include<stdio.h>

typedef struct node//node是标志名
{
    int a;
    //struct node p;//循环定义，未完成类型。编译器无法确定其大小，一个结构类型的大小为其成员的大小总和
    struct node * next;//指针成员，基类型为struct node *，就是一个指向本类型的指针
} NODE, *NODEPTR;

void traverse(NODEPTR head)//遍历链表的函数
{
    NODEPTR p = head;
    while (p != NULL)
    {
        printf("%d\n", p->a);
        p = p->next;//指针指向节点的指针域
    }
}

int main()
{
    NODE a = {1, NULL}, b = {2, NULL}, c = {3, NULL};
    //NULL是0的同义语,用在指针里就是空指针，不指向任何东西
    NODEPTR head, p;//变量类型是指针

    a.next = &b;
    b.next = &c;
    //通过next指针串在了一起，链表
    head = &a;//链表头指针 //a,b,c是节点
    traverse(head);

    return 0;
}