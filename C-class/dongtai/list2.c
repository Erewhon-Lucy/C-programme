//disable warning for VC++ compiler
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct 
{
    int x, y;
} point;


//类型定义
typedef point value_type;
typedef value_type* value_pointer;

typedef struct _node
{
    value_type data;
    struct _node *next;
} node, *nodeptr;

typedef struct 
{
    nodeptr head;
    size_t size;
} list, *listptr;

/*  callback是一种函数指针类型的别名
    这种类型的变量可以指向原型为：void (value_pointer) 的函数
    这种函数带有一个value_pointer类型的参数，返回类型是void
    例如，如果有变量和函数定义：
    callback p; //变量f是个指针，可以指向函数
    void f() {} //f函数的类型是：void ()
    void g(value_pointer) {} //g函数的类型是：void (value_pointer)
    int h(value)pointer) {}  //h函数的类型是：int (value_pointer)
    那么，指针p只能只想函数g，因为g的类型与p的基类型相同
    指向的方法有两种：
    1. 赋值： f = g;  f(); //等同于g()
    2. 作为函数参数，参见list_traverse
*/
typedef void (*callback)(value_pointer);

/*
    与callback类似，compare也是一种函数指针类型的别名
    compare指向的函数用于比较两个参数，返回比较结果
    两个参数怎样比较由指向的那个函数决定，原因是两个参数类型可能是多样化的
    例如：两个整数的比较和两个字符串的比较就是不一样的
    这种类型的指针主要用于排序
*/
typedef int (*compare)(value_pointer, value_pointer);

//链表操作原型声明
void list_init(listptr l);
bool list_push_front(listptr l, value_type value);
bool list_push_back(listptr l, value_type value);
bool list_insert(listptr l, size_t pos, value_type value);
size_t list_create(listptr l, value_pointer a, size_t len);
size_t list_size(listptr l);
bool list_empty(listptr l);
void list_clear(listptr l);
void list_traverse(listptr l, callback cb);
void list_sort(listptr l, compare comp_f);

//链表操作函数定义

void list_init(listptr l)
{
    l->size = 0;
    l->head = NULL;
}


//用给定的值生成一个新节点
nodeptr make_node(value_pointer vp)
{
    nodeptr p = (nodeptr)malloc(sizeof(node));
    p->data = *vp;
    p->next = NULL;

    return p;
}

//在链表头部添加一个节点
bool list_push_front(listptr l, value_type value)
{
    nodeptr p = make_node(&value);

    //如果链表为空，那么新节点就是链表中唯一的节点，也是第一个节点
    if (!list_empty(l))
        p->next = l->head;

    l->head = p;
    ++l->size;

    return true;
}

//在链表尾部添加一个节点
bool list_push_back(listptr l, value_type value)
{
    nodeptr p = make_node(&value);

    if (list_empty(l))
        //如果链表为空，那么新节点就是链表中唯一的节点，也是第一个节点
        l->head = p;
    else 
    {  
        //否则，从头开始找到链表的最后一个节点
        nodeptr q = l->head;
        while (q->next != NULL)
            q = q->next;
        
        q->next = p;
    }
        
    ++l->size;

    return true;
}

//在位置pos添加一个节点
//这意味着，新节点将会成为链表的第pos个节点（从1开始计数）
//原来的第pos个节点成为第pos+1个
//pos可能的值是从1到l->size+1
//如果是l->size+1，那意味着新节点将成为链表的最后一个节点
bool list_insert(listptr l, size_t pos, value_type value)
{
    nodeptr p, pre, q;

    //pos可能超出范围
    if (pos < 1 || pos > l->size + 1)
    {
        printf("insert out of range\n");
        return false;
    }

    if (pos == 1)
        return list_push_front(l, value);

    p = make_node(&value);
    //pre指向前一个结点，q指向当前节点
    pre = l->head;
    q = pre->next;
    //向后计数到pos - 1
    for (size_t i = 1; i < pos - 1; ++i)
    {
        pre = pre->next;
        q = q->next;
    }

    //此时，q指向原来的第pos个节点，pre指向它的前一个
    //因此，需要将新节点p链在pre后面，然后q链在p后面
    pre->next = p;
    p->next = q;
    ++l->size;

    return true;
}

//从数组创建一个链表
size_t list_create(listptr l, value_pointer a, size_t len)  //a is an array
{
    size_t i;

    for (i = 0; i < len; ++i)
        list_push_back(l, a[i]);

    return len;
}

//获得链表的结点数
size_t list_size(listptr l)
{
    return l->size;
}

//测试链表是否为空
bool list_empty(listptr l)
{
    return l->head == NULL;
}

//清空链表，删除所有节点
void list_clear(listptr l)
{
    nodeptr p = l->head, q;

    while (p != NULL)
    {
        q = p; //保存当前节点指针
        p = p->next; //工作指针移到下一个
        free(q); //删除q指向的节点
    }

    l->head = NULL;
    l->size = 0;
}

//遍历链表，用函数cb作为回调，去访问节点存储的数据
void list_traverse(listptr l, callback cb)
{
    nodeptr p = l->head;

    while (p != NULL)
    {
        cb(&p->data);
        p = p->next;
    }
}

size_t list_create_from_file(listptr l, const char *filename)
{
    FILE *fp;

    fp = fopen(filename ,"rt");
    if (fp == NULL)
    {
        printf("Cannot open file %s", filename);
        exit(1);
    }

    value_type v;
    size_t cnt = 0;
    while (!feof(fp))
    {
        fscanf(fp, "%d%d", &v.x, &v.y);
        list_push_back(l, v);
        ++cnt;
    }

    fclose(fp);

    return cnt;
}

void list_save_to_file(listptr l, const char *filename)
{
    FILE *fp;

    fp = fopen(filename ,"wt");
    if (fp == NULL)
    {
        printf("Cannot open file %s", filename);
        exit(1);
    }

    nodeptr p = l->head;

    while (p !=NULL)
    {
        fprintf(fp, "%d\t%d\n", p->data.x, p->data.y);
        p = p->next;
    }

    fclose(fp);

}

/*  链表排序
    排序肯定会用到两个数据的比较，因此用回调函数comp_f来进行这种比较
    要怎样比较由comp_f指针指向的函数决定
*/
void list_sort(listptr l, compare comp_f)
{
    
}

//用于打印的回调函数
void print(point *v) 
{
    printf("(%d,%d)\n", v->x,v->y); 
}

int comp_int(int* v1, int* v2)
{
    return *v1 - *v2;
};

//测试代码
int main()
{
    //int a[] = {54, 77, 23, 36, 19, 97, 41, 21, 33, 69};
    list l;
    // size_t pos;
    // int v;

    list_init(&l);

    list_create_from_file(&l,"data2.txt");

    // list_create(&l, a, 10);

    // printf("please input inserting position and value:");
    // scanf("%lu%d", &pos, &v);
    // list_insert(&l, pos, v);

    //list_traverse(&l, print);
    putchar('\n');

    list_save_to_file(&l, "data22.txt");

    list_clear(&l);

    return 0;
}

