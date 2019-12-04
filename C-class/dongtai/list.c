//disable warning for VC++ compiler
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//type declarations
typedef int value_type;//隔离，以防修改类型时改动太多，这样在改动类型时就改这里的int就好了
typedef value_type* value_pointer;

typedef struct _node//定义节点
{
    value_type data;//数据域
    struct _node *next;//指针域
} node, *nodeptr;

typedef struct 
{
    nodeptr head;//链表头指针
    size_t size;//链表的大小
} list, *listptr;

typedef void (*callback)(value_pointer);
typedef void (*compare)(value_pointer, value_pointer);

//operation prototype declarations
void list_init(listptr l);//链表初始化
bool list_push_front(listptr l, value_pointer vp);
bool list_push_back(listptr l, value_pointer vp);
bool list_insert(listptr l, size_t pos, value_pointer vp);
size_t list_create(listptr l, value_pointer a, size_t len);
size_t list_size(listptr l);
bool list_empty(listptr l);
void list_clear(listptr l);
void list_traverse(listptr l, callback cb);
void list_sort(listptr l, compare comp_f);

//operation definitions
void list_init(listptr l)//参数是链表指针
//void list_init(list l)//参数是链表对象
{
    l->head = NULL;
    l->size = 0;//链表初始化
}

bool list_push_front(listptr l, value_pointer vp)//插入到头
{
    nodeptr p =(nodeptr)malloc(sizeof(node));//产生一个新的节点
    p->data = *vp;//把数据填上
    p->next = NULL;//先指向空

    //if (l->head == NULL)//表明链表里一个节点都没有
    if (list_empty(l))
        l->head = p;//头指针直接指向新生成的p节点
    else
    {
        p->next = l->head;//指向原来的第一个节点
        l->head = p;//链表的头指针指向新生成的p节点,p节点
        //代码可简略
    }
    ++l->size;
    
    return true;
}

bool list_push_back(listptr l, value_pointer vp)//插入到尾
{
    nodeptr p =(nodeptr)malloc(sizeof(node));
    p->data = *vp;
    p->next = NULL;

    if (list_empty(l))//若链表为空
    {
        l->head = p;
        return true;
    }

    nodeptr q = l->head;//定义一个工作指针

    while (q->next != NULL)//判断指针域是否为空，即判断后面还有没有
    {
        q = q->next;
    }
    q->next = p;
    
    return true;
}

bool list_insert(listptr l, size_t pos, value_pointer vp)
{
    return true;
}

size_t list_create(listptr l, value_pointer a,size_t len)  //a is an array
{
    size_t i;

    for ( i = 0; i < len; i++)
    {
        //感受一下两种插入
        //list_push_front(l, &a[i]);//倒的
        list_push_back(l, &a[i]);//正的
    }
    
    return len;
}

size_t list_size(listptr l)
{
    return l->size;//直接返回链表大小
}

bool list_empty(listptr l)//测试链表是否为空
{
    //return true;
    return l->head == NULL;
}

void list_clear(listptr l)
{

}

void list_traverse(listptr l, callback cb)//遍历链表的方案
{
    nodeptr p = l->head;//p从第一个节点开始

    while (p != NULL)
    {
        cb(&p->data);
        p = p->next;
    }
}

void list_sort(listptr l, compare comp_f)
{
    
}

void print(int *v) { printf("%6d", *v); }

int main()
{
    int a[] = {54, 77, 23, 36, 19, 97, 41, 21, 33, 69};
    list l;

    list_init(&l);

    list_create(&l, a, 10);

    list_traverse(&l, print);

    return 0;
}

