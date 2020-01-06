#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX 100
#define GOODS_FILE_NAME "goodsinfo.txt"

#define MAX_ID_LEN 30
#define MAX_NAME_LEN 30
#define MAX_PRICE_LEN 30
#define MAX_DISCOUNT_LEN 30

typedef struct 
{
    char goods_id[MAX_ID_LEN];
    char goods_name[MAX_NAME_LEN];
    int goods_price;
    char goods_discount[MAX_DISCOUNT_LEN];
    int goods_amount;
    int goods_remain;
} GoodsInfo;


typedef struct node
{
    GoodsInfo data;
    struct node *next;
} GoodsList;


GoodsInfo read_goods_info();
void init_list(GoodsList **pL);
void destory_list(GoodsList **pL);
void destory_list_and_file(GoodsList **pL);
int save_to_file(GoodsList *L);
void output_one_item(GoodsList *L);
void output_all_items(GoodsList *L);
bool insert_item(GoodsList *L, GoodsInfo item, int choice);
bool delete_item(GoodsList *L, char* goods_id);
GoodsList* search_item(GoodsList *L, char* goods_id);
bool change_item(GoodsList *L, char* goods_id, GoodsInfo new_info);
void bubble_sort(GoodsList *L);
int read_line(char str[], int n);

int main(void)
{
    GoodsList* goodsList;
    init_list(&goodsList);
    GoodsInfo item;
    char temp_id[MAX_ID_LEN];
    while (1) {
        int choice;
        printf("超市商品管理系统\n");
        printf("********************************************\n");
        printf("1.显示所有商品的信息:\n");
        printf("2.修改某个商品的信息:\n");
        printf("3.插入某个商品的信息:\n");
        printf("4.删除某个商品的信息:\n");
        printf("5.查找某个商品的信息:\n");
        printf("6.商品存盘并退出系统:\n");
        printf("7.对商品价格进行排序:\n");
        printf("8.(慎用)删除所有内容:\n");
        printf("其他.不存盘并退出系统:\n");
        printf("********************************************\n");
        printf("输入您的选择: ");

        scanf("%d", &choice);
        switch (choice) {
        case 1:
            output_all_items(goodsList);
            break;
        case 2:
            item = read_goods_info();
            printf("输入要修改记录的 ID：");
            read_line(temp_id, MAX_ID_LEN);
            change_item(goodsList, temp_id, item);
            break;
        case 3:
            item = read_goods_info();
            int pos;
            printf("输入数字表明你要插入的商品位置：0.商品列表尾部 1.商品列表头部 i.商品列表中间第i号位置\n");
            scanf("%d", &pos);
            insert_item(goodsList, item, pos);
            break;
        case 4:
            printf("输入要删除记录的 ID：");
            read_line(temp_id, MAX_ID_LEN);
            delete_item(goodsList, temp_id);
            break;
        case 5:
            printf("输入要查找记录的 ID：");
            read_line(temp_id, MAX_ID_LEN);
            search_item(goodsList, temp_id);
            break;
        case 6:
            save_to_file(goodsList);
            printf("您已经存盘并退出超市商品管理系统!\n");
            return 0;
        case 7:
            bubble_sort(goodsList);
            break;
        case 8:
            destory_list_and_file(&goodsList);
            printf("您已经删除商品文件内容以及链表内容!\n");
            break;
        default:
            printf("您已经退出超市商品管理系统!\n");
            destory_list(&goodsList);
            return 0;
        }
    }
}

extern int CurrentCnt; // 请不要删除本行的全局变量声明，否则检查不通过

void init_list(GoodsList** L)
{
    FILE* fp;
    GoodsInfo goodsInfo;
    GoodsList *p, *r;
    (*L) = (GoodsList*)malloc(sizeof(GoodsList));
    r = (*L);
    if ((fp = fopen(GOODS_FILE_NAME, "r")) == NULL) {
        if ((fp = fopen(GOODS_FILE_NAME, "w")) == NULL)
            printf("提示:不能创建商品文件\n");
    } else {
        while (!feof(fp)) {
            fscanf(fp, "%s", goodsInfo.goods_id);
            fscanf(fp, "\t%s", goodsInfo.goods_name);
            fscanf(fp, "\t%d", &goodsInfo.goods_price);
            fscanf(fp, "\t%s", goodsInfo.goods_discount);
            fscanf(fp, "\t%d", &goodsInfo.goods_amount);
            fscanf(fp, "\t%d\n", &goodsInfo.goods_remain);
            p = (GoodsList*)malloc(sizeof(GoodsList));
            p->data = goodsInfo;
            r->next = p;
            r = p;
            CurrentCnt++;
        }
    }
    fclose(fp);
}

bool insert_item(GoodsList* L, GoodsInfo goodsInfo, int choice)
{
    if (choice == 0) {
        while (L->next != NULL)
            L = L->next;
        GoodsList* GL = (GoodsList*)malloc(sizeof(GoodsList));
        GL->data = goodsInfo;
        GL->next = NULL;
        L->next = GL;
        return true;
    }
    GoodsList* pre = L;
    while (choice--) {
        pre = L;
        if (L->next == NULL)
            return false;
        L = L->next;
    }
    GoodsList* GL = (GoodsList*)malloc(sizeof(GoodsList));
    GL->data = goodsInfo;
    GL->next = L;
    pre->next = GL;
    return true;
}

bool delete_item(GoodsList* L, char* goods_id)
{
    GoodsList* pre = L;
    while (strcmp(L->data.goods_id, goods_id) && L->next) {
        pre = L;
        L = L->next;
    }
    if (strcmp(L->data.goods_id, goods_id) == 0) {
        if (L->next == NULL)
            pre->next = NULL;
        else
            pre->next = L->next;
        free(L);
        return true;
    }
    return false;
}

GoodsList* search_item(GoodsList* L, char* goods_id)
{
    GoodsList* pre = L;
    while (strcmp(L->data.goods_id, goods_id) && L->next) {
        pre = L;
        L = L->next;
    }
    if (strcmp(L->data.goods_id, goods_id) == 0) {

        return L;
    }
    return NULL;
}

bool change_item(GoodsList* L, char* goods_id, GoodsInfo new_info)
{
    GoodsList* pre = L;
    while (strcmp(L->data.goods_id, goods_id) && L->next) {
        pre = L;
        L = L->next;
    }
    if (strcmp(L->data.goods_id, goods_id) == 0) {
        L->data = new_info;
        return true;
    }
    return false;
}

void output_one_item(GoodsList* p)
{
    if (p != NULL) {
        printf("%s\n%s\n%d\n%s\n%d\n%d\n",
            p->data.goods_id, p->data.goods_name, p->data.goods_price, p->data.goods_discount, p->data.goods_amount, p->data.goods_remain);
    }
}

void output_all_items(GoodsList* L)
{
    while (L->next) {
        output_one_item(L->next);
        L = L->next;
    }
}

void destory_list(GoodsList** L)
{
    GoodsList* LL = *L;
    GoodsList* pre = LL;
    while (LL->next) {
        pre = LL->next;
        free(LL);
        LL = pre;
    }
    free(LL);
}

void destory_list_and_file(GoodsList** L)
{
    destory_list(L);
    remove("goodinfo.txt");
}

int save_to_file(GoodsList* L)
{
    FILE* fp;
    fp = fopen("goodsinfo.txt", "wt");
    while (L->next) {
        GoodsInfo GI = L->data;
        sprintf(fp, "%s\t%s\t%3d\t%s\t%d\t%d",
            GI.goods_id, GI.goods_name, GI.goods_price, GI.goods_discount, GI.goods_amount, GI.goods_remain);
        L = L->next;
        if (L->next != NULL)
            sprintf(fp, "\n");
    }
}

void bubble_sort(GoodsList* L)
{
    int i, j;
    GoodsList *p, *q;

    for (i = 0; i < CurrentCnt - 1; ++i) {
        p = L->next;
        q = p->next;
        for (j = 0; j < CurrentCnt - i - 1; ++j) {
            if (p->data.goods_price > q->data.goods_price) {
                GoodsInfo t = p->data;
                p->data = q->data;
                q->data = t;
            }
            p = p->next;
            q = q->next;
        }
    }
}

GoodsInfo read_goods_info()
{
    GoodsInfo goodsInfo;

    read_line(goodsInfo.goods_id, MAX_ID_LEN);
    read_line(goodsInfo.goods_name, MAX_NAME_LEN);
    scanf("%d", &goodsInfo.goods_price);
    read_line(goodsInfo.goods_discount, MAX_DISCOUNT_LEN);
    scanf("%d%d", &goodsInfo.goods_amount, &goodsInfo.goods_remain);
    return goodsInfo;
}