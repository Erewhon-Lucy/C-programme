//disable warning for VC++ compiler
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "list_point.h"

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

/*  链表排序
    排序肯定会用到两个数据的比较，因此用回调函数comp_f来进行这种比较
    要怎样比较由comp_f指针指向的函数决定
*/
void list_sort(listptr l, compare comp_f)
{
    int i, j;
    nodeptr p, q;

    for (i = 0; i < l->size - 1; ++i)
    {
        p = l->head;
        q = p->next;
        for (j = 0; j < l->size - i - 1; ++j)
        {
            if (comp_f(&p->data, &q->data) >= 0)
            { // block
                value_type t = p->data;
                p->data = q->data;
                q->data = t;
            } 
            p = p->next;
            q = q->next;
        } 
    }
}

size_t list_create_from_file(listptr l, const char *filename)
{
    FILE *fp;

    fp = fopen(filename ,"rt");
    if (fp == NULL) // if (!fp)
    {
        printf("Cannot open file %s.", filename);
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
    if (fp == NULL) // if (!fp)
    {
        printf("Cannot open file %s.", filename);
        exit(1);
    }

    nodeptr p = l->head;
    while (p != NULL)
    {
        fprintf(fp, "%d\t%d\n", p->data.x, p->data.y);
        p = p->next;
    }

    fclose(fp);
}

