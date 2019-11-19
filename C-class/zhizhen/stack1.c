#include<stdio.h>
#include<stdlib.h>//标准C库

#define DEPTH 128

int stack[DEPTH];//用数组来表示栈
int top;

void init()//初始化堆栈
{
    top = 0;   
}

void push(int v)//和stack的int一样
{
    if (top == DEPTH - 1)//此时已经是最后一个元素了
    {
        printf("stack overflow\n");
        exit(-1);//直接停止执行程序，返回一个非0值
    }
    
    //++top;//指针的移动,先动指针
    stack[++top] = v;   
}

int pop()//返回stack里面的值，所以是返回类型是int;
{
    
    if (top == 0)//堆栈走不下去了，top没法再减了
    {
        printf("stack underflow\n");
        exit(-2);
    }

    //--top;
    return stack[top--];//先取值再减
    //浪费了栈底的那个单元
}

int main()
{
    int i;

    for ( i = 0; i < DEPTH - 1; i++)//不溢出
    {
        push(i);
    }

    for ( i = 0; i < DEPTH; i++)//栈底溢出
    {
        printf("%4d", pop());//LIFO，后进先出
    }
    
    return 0;//如果正常运行，程序正常退出，则程序返回值为0
             //若之前前用了exit(-1)，则表示程序异常退出，不过程序退出码和2的8次方有关
}