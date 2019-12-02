#include <stdio.h>

typedef char GENDER;
const GENDER MALE = 'M';
const GENDER FEMALE = 'F';

typedef struct
{
    unsigned year, month, day;
} date;

typedef struct
{
    unsigned sid;
    char name[32];//名字是字符串
    GENDER gender;
    date dob;//多加一个成员date
    //结构嵌入结构:在C语言中和分开定义一样
    // struct date
    // {
    //     unsigned year, month, day;
    // } dob;   
} student;

int main()
{
    // student s;
    student s = {1000, "Lao Bai", MALE, {2001, 12, 31}};
    //对结构变量进行初始化，凡是没初始化的都会被赋值为零

    student *p = &s;//指针初始化，p指向结构变量s

    // scanf("%u%s %c", &s.sid, s.name, &s.gender);//分隔符是空格,%s后面再加一个空格。
    // //%u->unsigned  数组就是指针，所以不用->
    printf("%u,%s,%s,%u\n",s.sid, p->name, s.gender == MALE ? "MALE" : "FEMALE", p->dob.year);
    //s.dob.year 级联
    //那个相当于(p->dob).year

    return 0;
}