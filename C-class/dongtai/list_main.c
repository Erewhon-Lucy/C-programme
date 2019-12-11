//disable warning for VC++ compiler
#define _CRT_SECURE_NO_WARNINGS 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "list_point.h"

//用于打印的回调函数
void print(point *v) 
{ 
    printf("(%d,%d)\n", v->x, v->y); 
}

int comp_point(point* v1, point* v2)
{
    return (v1->x * v1->x + v1->y * v1->y)
    - (v2->x * v2->x + v2->y * v2->y);
}

//测试代码
int main()
{
    //int a[] = {54, 77, 23, 36, 19, 97, 41, 21, 33, 69};
    list l;
    // size_t pos;
    // int v;

    list_init(&l);

    list_create_from_file(&l, "data2.txt");

    //list_create(&l, a, 10);

    // printf("please input inserting position and value:");
    // scanf("%lu%d", &pos, &v);
    // list_insert(&l, pos, v);

    list_sort(&l, comp_point);

    list_traverse(&l, print);
    putchar('\n');

    list_save_to_file(&l, "data22.txt");
    
    list_clear(&l);

    return 0;
}

