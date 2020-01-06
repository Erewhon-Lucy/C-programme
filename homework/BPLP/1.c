#include <string.h>
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

#define LEN sizeof (struct student)

struct student
{
    char number[20];//用户序号
    char name[100];//用户姓名
    char danwei[100];//用户单位
    char phone[20];//电话号码
    char home[100];//家庭地址
    struct student *next;
};

void face(void); /*主菜单函数*/
void print(struct student *head);
struct student *append(struct student *head);//增添电子通讯录中的内容，即创建连表过程
struct student *del(struct student *head);//电子通讯录的维护（删除），通过输入联系人姓名删除联系人数据
void search(struct student *head);//电子通讯录的查找，关键字为用户姓名；
void searchByNumber(struct student *head);//电子通讯录的查找，关键字为用户序号；

void main()
{
    // FILE *fp1,*fp2;
    int c;//功能选择需要的号码
    system("cls");
    //system("color 2f");
    system("cls");
    struct student *head= NULL;
    {
        face();
        printf("选择你需要操作的功能号码:");
        scanf("%d",&c);
        getchar();
        switch(c)
        {
            case 0:head=append(head);break;
            case 1:print(head);break;
            case 4:head=del(head);break;
            case 2:search(head);break;
            case 3:searchByNumber(head);break;
            case 5:exit(0);break;
            default :printf("Enter error!!\n");
        }
        printf("*****************\n");
        printf("◇◆请按ENTER返回功能操作菜单◇◆\n");
        printf("*****************\n");
        getchar();
        system("CLS");
    }
}

void face(void) /*主菜单函数*/
{
    printf("***************************MENU*****************************************");
    printf("\t\t\t\t☆★☆★☆★ ~_~ ~_~ ~_~ ☆★☆★☆★\n");
    printf("\n\t\t\t☆★☆★");
    printf("\n\n\t☆★选择你需要操作的功能:☆★(现无记录，建议先填加记录)★☆\n");
    printf("\n");
    printf("\t\t\t0.【输入通讯录信息〗\n");
    printf("\t\t\t1.〖显示通讯录中所有记录】\n");
    printf("\t\t\t4.【删除记录〗\n");
    printf("\t\t\t2.〖按姓名查找显示记录】\n");
    printf("\t\t\t3.【按序号查找显示记录〗\n");
    printf("\t\t\t5〖退出!!】\n");
    printf("\n");
    printf("\t☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★");
    printf("\n\n********************************************************************\n\n");
}

void print(struct student *head)
{
    struct student *p;
    p=head;
    system("CLS");//调用 DOS 命令 CLS 能够清屏
    printf("*************************************************************\n");
    printf("==================== → 用 户 信 息 记 录 表 ←===================\n");
    printf("*************************************************************\n");
    if(head!=NULL)
        do
        {
            printf("用户序号:%s\n",p->number);
            printf("联系人姓名:%s\n",p->name);
            printf("用户单位:%s\n",p->danwei);
            printf("联系人电话号码:%s\n",p->phone);
            printf("学生地址:%s\n",p->home);
            printf("********************************************************\n");
            p=p->next;
        } while (p!=NULL);
    else
    {
        printf("对不起!!没有任何联系人记录!!\n\n");
        printf("=============================================================\n");
    }
}

//增添电子通讯录中的内容，即创建连表过程
struct student *append(struct student *head)
{
    struct student *p0=NULL,*p1,*p2;//p0 为要插入的新节点
    p1 = head;
    p2 = head;
    system("CLS");
    printf("\n\n***********************************************************\n");
    printf("\t\t 你能在此目录下创建并添加联系人信息");
    printf("\n***********************************************************\n");
    p0 = (struct student *)malloc(LEN);
    printf("请输入用户序号:");
    gets(p0->number);
    printf("请输入联系人姓名:");
    gets(p0->name);
    printf("请输入联系人单位");
    gets(p0->danwei);
    printf("请输入联系人电话号码:");
    gets(p0->phone);
    printf("请输入联系人地址:");
    gets(p0->home);
    //对插入的节点排序，按姓名的拼音顺序
    if(head == NULL)
    {
        head = p0;
        p0->next = NULL;
    }
    else
    {
        while((strcmp(p0->name, p1->name) > 0) && (p1->next != NULL))
        {
            p2 = p1;
            p1 = p1->next;
        }
        if((strcmp(p0->name, p1->name)) <= 0)
        {
            if(head == p1)
            head = p0;

            else
            p2->next = p0;
            p0->next = p1;
        }
        else
        {
            p1->next = p0;
            p0->next = NULL;
        }
    }
    printf("恭喜你!!成功添加了联系人信息!!");
    printf("\n************************************************************\n");
    printf("\n\n");
    return(head);
}

//电子通讯录的维护（删除），通过输入联系人姓名删除联系人数据
struct student *del(struct student *head)
{
    struct student *p1,*p2;
    char name[100];
    system("CLS");
    printf("\n\n************************************************************\n");
    printf("================= → 用 户 信 息 记 录 删 除 功 能 ←===============\n");
    printf("************************************************************\n");
    printf("输入要删除的联系人姓名:");
    gets(name);
    p1 = head;
    if (head == NULL)
    {
        printf("很抱歉!!没有任何联系人纪录!!\n");
        printf("\n*******************************************************\n")
        ;
        return(head);
    }
    while(p1 != NULL)
    {
        if(strcmp(p1->name,name) == 0)
        {
            if(p1 == head)
            head = p1->next;
            else p2->next = p1->next;
            free(p1);
            printf("删除记录成功!!\n");
            return(head);
        }
        p2 = p1;
        p1 = p1->next;
    }
    printf("对不起!!没有要删除的联系人纪录!!\n");
    return(head);
}

//电子通讯录的查找，关键字为用户姓名；
void search(struct student *head)
{
    struct student *p1,*p2;
    char name[20];
    p1 = head;
    p2 = p1;
    system("CLS");
    printf("\n**************************************************************\n");
    printf("================ → 用 户 信 息 记 录 查 询 功 能 ←==================\n");
    printf("**************************************************************\n");
    printf("输入要查找联系人的姓名:");
    gets(name);
    while(p1 != NULL)
    {
        if(strcmp(p1->name, name) == 0)
        {
            printf("联系人序号:");
            puts(p1->number);
            printf("联系人姓名:");
            puts(p1->name);
            printf("联系人电话号码:");
            puts(p1->phone);
            printf("联系人地址:");
            puts(p1->home);
            //printf("联系人出生日期:");
            // puts(p1->birthday);
            printf("\n=============================================================\n");
            break;
        }
        p2 = p1;
        p1 = p1->next;
    }

    if(p1 == NULL)

    printf("对不起!!没有该联系人的纪录!!\n");
}

//电子通讯录的查找，关键字为用户序
void searchByNumber(struct student *head)
{
    struct student *p1,*p2;
    char number[20];
    p1 = head;
    p2 = p1;
    system("CLS");
    printf("\n**************************************************************\n");
    printf("================ → 用 户 信 息 记 录 查 询 功 能 ←==================\n");
    printf("**************************************************************\n");
    printf("输入要查找联系人序号:");
    gets(number);
    while(p1 != NULL)
    {
        if(strcmp(p1->number,number) == 0)
        {
            printf("联系人序号:");
            puts(p1->number);
            printf("联系人姓名:");
            puts(p1->name);
            printf("联系人电话号码:");
            puts(p1->phone);
            printf("联系人地址:");
            puts(p1->home);
            printf("\n=============================================================\n");
            break;
        }
        p2 = p1;
        p1 = p1->next;
    }
    if(p1 == NULL)
    printf("对不起!!没有该联系人的纪录!!\n");
}
