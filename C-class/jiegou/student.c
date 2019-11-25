#include <stdio.h>

typedef char GENDER;
const GENDER MALE = 'M';
const GENDER FEMALE = 'F';

typedef struct
{
    unsigned sid;
    char name[32];//名字是字符串
    GENDER gender;
} student;

int main()
{
    student s;

    scanf("%u%s %c", &s.sid, s.name, &s.gender);//分隔符是空格
    //%u->unsigned  数组就是指针，所以不用->
    printf("%u,%s,%s\n",s.sid, s.name, s.gender == MALE ? "MALE" : "FEMALE");

    return 0;
}