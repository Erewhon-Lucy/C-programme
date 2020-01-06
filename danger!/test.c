#include <stdio.h>

void main()
{
    char *s = "China Beijing";
    char *p;
    p = s;
    while ((*p)!=' ')
       p++;
    //p = '\0';
    printf("%s\n",s);
    printf("%s\n",p);
}