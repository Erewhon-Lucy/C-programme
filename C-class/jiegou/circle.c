#include <stdio.h>
#include <stdlib.h>//为使用rand()
#include <time.h>//为使用rand()

#define PI 3.1415926
//const double PI = 3.1415926;也可以

// double x, y;//这三个是全局变量,没有表现出他们的内在联系，内聚性
// double r;
//完整用法：
// struct _circle//定义了一个结构类型, _circle是标签名,编码规范加个_
// {
//     double x, y;
//     double r;
// };//这里有个;别忘了
//typedef old_type new_type;
//typedef int A[5];
// typedef struct _circle Circle;//Circle是别名(alias)，代表strct _circle

typedef struct
{
    double x, y;
    double r;//x,y,r是结构体的成员，是成员变量
} circle;

double area(circle *c)//他的参数是个圆，语义符合
{
    return (*c).r * c->r * PI;//-和>之间没有空格，同样是成员选择运算符，左边是指针
}

circle make_circle()
{
    circle t;

    t.x = rand() % 100;
    t.y = rand() % 100;
    t.r = rand() % 10;
}

int main()
{
    circle c;//circle是类型，不是变量！c是结构体变量，定义了c之后，会为每个成员分配存储空间

    c.x = 1.0;//“.”：成员选择运算符
    c.y = 2.0;
    c.r = 1.0;

    int i;

    srand(time(NULL));

    for ( i = 0; i < 5; i++)
    {
        c = make_circle();
        printf("(%.2lf,%.2lf)==>%.2lf\n", c.x, c.y, area(&c));
    }
    
    printf("%lf\n",area(&c));//直接调用c
    return 0;
}