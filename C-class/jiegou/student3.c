#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    char name[32];
    GENDER gender;
} student;

void bubble_sort(student a[], int len)
{
    int i, j;
    student t;

    for (i = 0; i < len - 1; ++i)
        for (j = 0; j < len - i - 1; ++j)
            if (strcpy(a[j].name, a[j + 1].name) > 0)
            { // block
                student t = a[j];//C语言允许两个结构变量直接赋值，即使结构中有数组
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
}

int main()
{
    student s[5] = {//注意结构数组初始化，中间隔逗号不是分号
        {1000, "ken", MALE},
        {1001, "Zoe", FEMALE},
        {1002, "David", MALE},
        {1003, "David", MALE},
        {1004, "David", MALE},
    } ;

    int i;
    student *p;

    bubble_sort(s, 5);
    p = s;

    for ( i = 0; i < 5; ++i, ++p)
    {
        printf("%u,%s,%s\n",p->sid, p->name, p->gender == MALE ? "MALE" : "FEMALE");
    }
    


    // scanf("%u%s %c", &s.sid, s.name, &s.gender);//分隔符是空格,%s后面再加一个空格。
    // //%u->unsigned  数组就是指针，所以不用->

    return 0;
}