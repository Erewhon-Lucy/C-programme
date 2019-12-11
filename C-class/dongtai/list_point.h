#pragma once
#include <stdio.h>
#include <stdlib.h>

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
extern void list_init(listptr l);
extern bool list_push_front(listptr l, value_type value);
extern bool list_push_back(listptr l, value_type value);
extern bool list_insert(listptr l, size_t pos, value_type value);
extern size_t list_create(listptr l, value_pointer a, size_t len);
extern size_t list_size(listptr l);
extern bool list_empty(listptr l);
extern void list_clear(listptr l);
extern void list_traverse(listptr l, callback cb);
extern void list_sort(listptr l, compare comp_f);
extern size_t list_create_from_file(listptr l, const char *filename);
extern void list_save_to_file(listptr l,const char *filename);
