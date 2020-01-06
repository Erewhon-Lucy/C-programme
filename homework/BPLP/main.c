#include "head.h"

void face();
void print(struct student *head);
struct student *append(struct student *head);
struct student *del(struct student *head);
void searchByName(struct student *head);
void searchByArea(struct student *head);
void saveToFile(struct student *head, const char *filename);

void face()
{
    initscr(); //初始化屏幕
    line();
    move(2, COLS / 2 - 2); //移动光标
    addstr("你好");        //输出字符串
    move(3, COLS / 2 - 11);
    addstr("我是一个没有感情的密码本\n");
    line();
    move(5, COLS / 2 - 4);
    addstr("请操♂作我\n\n");
    addstr("1.记下一个密码\n");
    addstr("2.看看我的密码本\n");
    addstr("3.删除一组密码\n");
    addstr("4.按账户名找到一个密码\n");
    addstr("5.按登录环境查找一个密码\n");
    addstr("6.离开没有感情的密码本\n\n");
    line();
    move(15, COLS / 2 - 5);
    addstr("开始操♂作吧！\n");
    addstr("你的操作：");
    echo(); //启动屏幕响应
            // char ch;
    // while(ch=getch()!='\n')//留住除了回车所有响应内容
    // {

    // }
    // endwin();//关闭窗口
    /*警告！ 此函数在调试时为main函数
    调用时应更改名称
    为测试效果 此函数包含读取字符串部分
    请组合至main函数*/
}
void print(struct student *head)
{
    struct student *p;
    p = head;
    clear();
    if (head != NULL)
        do
        {
            printw("你的账户名字:%s\n", p->name);
            printw("这个账户的密码:%s\n", p->code);
            printw("密保问题:%s\n", p->answer);
            printw("账户是用来登录这个的:%s\n", p->area);
            line();
            p = p->next;
        } while (p != NULL);
    else
    {
        addstr("你傻了你的密码没保存在这\n\n");
        line();
    }
    getch();
}
void searchByName(struct student *head)
{
    char name[50];
    struct student *p1, *p2;
    p1 = head;
    p2 = p1;
    clear();
    addstr("你要回忆的密码 它的账户叫啥\n");
    line();
    scanw("%s", &name);
    while (p1 != NULL)
    {
        if (strcmp(p1->name, name) == 0)
        {
            printw("它的密码是:%s\n", p1->code);
            printw("密保答案是:%s\n", p1->answer);
            printw("它用来登录这个:%s\n", p1->area);
            break;
        }
        p2 = p1;
        p1 = p1->next;
    }

    if (p1 == NULL)

        printw("醒醒你还没登记过这个账户 !!\n");
}

void searchByArea(struct student *head)
{
    char area[50];
    struct student *p1, *p2;
    p1 = head;
    p2 = p1;
    clear();
    addstr("你要回忆的密码 在哪里登录\n");
    line();
    scanw("%s", &area);
    while (p1 != NULL)
    {
        if (strcmp(p1->area, area) == 0)
        {
            printw("它的账户是:%s\n", p1->name);
            printw("它的密码是:%s\n", p1->code);
            printw("密保答案是:%s\n", p1->answer);
            break;
        }
        p2 = p1;
        p1 = p1->next;
    }

    if (p1 == NULL)

        printw("醒醒你还没登记过这个账户 !!\n");
}

struct student *append(struct student *head)
{
    struct student *p0 = NULL, *p1, *p2;
    p1 = head;
    p2 = head;
    clear();
    addstr(" 你能在这里保存你愚蠢脑瓜记不住的密码\n");
    line();
    p0 = (struct student *)malloc(LEN);
    addstr("你的账户:\n");
    scanw("%s", &p0->name);
    addstr("你的密码:\n");
    scanw("%s", p0->code);
    addstr("密保问题:\n");
    scanw("%s", &p0->answer);
    addstr("顺便记一下它在哪登录免得你的憨憨脑子忘记:\n");
    scanw("%s", &p0->area);
    //根据用户名排序
    if (head == NULL)
    {
        head = p0;
        p0->next = NULL;
    }
    //
    else
    {
        while ((strcmp(p0->name, p1->name) > 0) && (p1->next != NULL))
        {
            p2 = p1;
            p1 = p1->next;
        }
        if ((strcmp(p0->name, p1->name)) <= 0)
        {
            if (head == p1)
                head = p0;

            else
            {
                p2->next = p0;
                p0->next = p1;
            }
        }
        else

        {
            p1->next = p0;
            p0->next = NULL;
        }
    }
    printw("恭喜你!!可以从脑子里忘记你的密码了 \n"); //恭喜你 可以从脑子里忘记你的密码了
    saveToFile(head,"1.txt");
    line();
    getch();
    return (head);
}
struct student *del(struct student *head)
{
    struct student *p1, *p2;
    char name[100];
    clear();
    printw("你哪个号没了？:"); //你哪个号没了？
    scanw("%s", &name);
    p1 = head;
    if (head == NULL)
    {
        printw("你还没临幸过这个莫得感情的密码本\n"); //你还没临幸过这个莫得感情的密码本
        line();
        return (head);
    }
    while (p1 != NULL)
    {
        if (strcmp(p1->name, name) == 0)
        {
            if (p1 == head)
                head = p1->next;
            else
                p2->next = p1->next;
            free(p1);
            printw("恭喜！你号没了!!\n"); //你号没了
            //save
            getch();
            return (head);
        }
        p2 = p1;
        p1 = p1->next;
    }
    printw("你记错了你根本就没来登记过它\n"); //你记错了你根本就没来登记过它
    getch();
    return (head);
}
int list_create_from_file(struct student *head,const char *filename)
{
    FILE *fp;
    int cnt;
    fp=fopen(filename,"rt");
    if (fp==NULL)
    {
        printf("cannot find %s.", filename);
        exit(1);
    }
    
    while (!feof(fp))
    {
        fscanf(fp,"%s\t%s\t%s\t%s\n",head->name,head->code,head->answer,head->area);
        cnt++;
    }

    return cnt;
    
}

void saveToFile(struct student *head, const char *filename)
{
    FILE *fp;
    fp = fopen(filename, "wt");
    if (fp == NULL)
    {
        printf("cannot find %s.", filename);
        exit(1);
    }
    while (head != NULL)
    {
        fprintf(fp, "%s\t", head->name);
        fprintf(fp, "%s\t", head->code);
        fprintf(fp, "%s\t", head->answer);
        fprintf(fp, "%s\n", head->area);
        head=head->next;
    }
    
    fclose(fp);
}

int main()
{
    struct student *head = NULL;
    int input;

    head = (struct student *)malloc(LEN);

    setlocale(LC_ALL, "");
    list_create_from_file(head, "1.txt");
    while (1)   
    {
        face();
        scanw("%d", &input);
        printw("%d", input);
        getch();
        switch (input)
        {
        case 1:
            head = append(head);
            break;
        case 2:
            print(head);
            break;
        case 3:
            head = del(head);
            break;
        case 4:
            searchByName(head);
            break;
        case 5:
            searchByArea(head);
            break;
        case 6:
            clear();
            endwin();
            return 0;
            break;
        }
        clear();
    }

    getch();
    endwin();
    return 0;
}