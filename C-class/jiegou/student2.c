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
    char name[32];
    GENDER gender;
} student;

int main()
{
    student s[3] = {//注意结构数组初始化，中间隔逗号不是分号
        {1000, "ken", MALE},
        {1001, "Zoe", FEMALE},
        {1002, "David", MALE}
    } ;

    int i;

    for ( i = 0; i < 3; i++)
    {
        printf("%u,%s,%s\n",s[i].sid, s[i].name, s[i].gender == MALE ? "MALE" : "FEMALE");
    }
    


    // scanf("%u%s %c", &s.sid, s.name, &s.gender);//分隔符是空格,%s后面再加一个空格。
    // //%u->unsigned  数组就是指针，所以不用->

    return 0;
}