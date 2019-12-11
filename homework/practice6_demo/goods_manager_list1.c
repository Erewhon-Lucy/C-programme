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

int main()
{
    GoodsInfo info;
    GoodsList list;
    output_all_items(&list);
    search_item(&list, '0');
    insert_item(&list, info, 0);
    save_to_file(&list);
    change_item(&list, '0', info);
    bubble_sort(&list);
    return 0;
}

extern int CurrentCnt;

//初始化
void init_list(GoodsList** L)
{
    char * goodlist;
    FILE *fp;
    *L = malloc(sizeof(GoodsList));
    GoodsList** cur = &(*L);
    int e;
    while(!feof(fp))
    {
        GoodsList* new_node = malloc(sizeof(GoodsList));
        fscanf(fp, "%d", &e);
        new_node->data = e;
        (*cur)->next = new_node;
        (*cur) = new_node;
    }
    (*cur)->next = NULL;
    fclose(fp);
    printf("%d\t",(*cur)->data);
    (*cur) = (*cur)->next;
}

//插入
bool insert_item(GoodsList* L, GoodsInfo goodsInfo, int choice)
{
    GoodsList *cur, *prev, *new_node;
    new_node = malloc(sizeof(GoodsList));
    new_node->data = goodsInfo;
    if (choice == 0)
    {
        for (prev = NULL, cur = L; cur != NULL; prev = cur, cur = cur->next)
            ;
        new_node->next = NULL;
        if (prev == NULL)
            L = new_node;
        else
            prev->next = new_node;
        return true;
    } else if (choice == 1) {
        if (L->next == NULL)
            L->next = new_node;
        else {
            new_node->next = L->next;
            L->next = new_node;
        }
        return true;
    } else {
        int pos = 1;
        for (prev = NULL, cur = L; cur != NULL; prev = cur, cur = cur->next) {
            if (pos == choice)
                break;
            pos++;
        }
        if (pos < choice)
            return false;
        new_node->next = cur->next;
        cur->next = new_node;
        return true;
    }
}

//删除节点
bool delete_item(GoodsList* L, char* goods_id)
{
    int len1 = strlen(goods_id), i;
    GoodsList** pre;
    for (pre = &L, L = L->next; L != NULL; pre = &L, L = L->next) {
        int len2 = strlen((L->data).goods_id);
        if (len1 != len2)
            continue;
        bool flag = true;
        for (i = 0; i < len2; i++)
            if (goods_id[i] != (L->data).goods_id[i]) {
                flag = false;
                break;
            }
        if (flag) {
            (*pre)->next = L->next;
            free(L);
            return true;
        }
    }
    return false;
}

//查找
GoodsList* search_item(GoodsList* L, char* goods_id)
{
    int len1 = strlen(goods_id), i;
    for (L = L->next; L != NULL; L = L->next) {
        int len2 = strlen((L->data).goods_id);
        if (len1 != len2)
            continue;
        bool flag = true;
        for (i = 0; i < len2; i++)
            if (goods_id[i] != (L->data).goods_id[i]) {
                flag = false;
                break;
            }
        if (flag == true)
            return true;
    }
    return NULL;
}

//修改
bool change_item(GoodsList* L, char* goods_id, GoodsInfo new_info)
{
    int len1 = strlen(goods_id), i;
    for (L = L->next; L != NULL; L = L->next) {
        int len2 = strlen((L->data).goods_id);
        if (len1 != len2)
            continue;
        bool flag = true;
        for (i = 0; i < len2; i++)
            if (goods_id[i] != (L->data).goods_id[i]) {
                flag = false;
                break;
            }
        if (flag == true) {
            L->data = new_info;
            return true;
        }
    }
    return false;
}

//显示单个
void output_one_item(GoodsList* p)
{
    if (p != NULL) {
        GoodsInfo temp = p->data;
        printf("%s\n%s\n%d\n%s\n%d\n%d\n", temp.goods_id, temp.goods_name, temp.goods_price, temp.goods_discount, temp.goods_amount, temp.goods_remain);
    }
}

//显示所有
void output_all_items(GoodsList* L)
{
    for (L = L->next; L != NULL; L = L->next) {
        output_one_item(L);
    }
}

//释放链表
void destory_list(GoodsList** L)
{
    GoodsList* cur;
    cur = *L;
    (*L)->next = NULL;
    for (*L = cur->next; *L != NULL;) {
        cur = *L;
        *L = cur->next;
        free(cur);
    }
}

//释放列表并删除文件
void destory_list_and_file(GoodsList** L)
{
    destory_list(L);
    remove("goodinfo.txt");
}

//保存文件
int save_to_file(GoodsList* L)
{
    FILE* txt = fopen("goodsinfo.txt", "w");
    int num = 0;
    for (L = L->next; L != NULL; L = L->next) {
        num++;
        GoodsInfo temp = L->data;
        fprintf(txt, "%s\n%s\n%d\n%s\n%d\n%d\n", temp.goods_id, temp.goods_name, temp.goods_price, temp.goods_discount, temp.goods_amount, temp.goods_remain);
    }
    fclose(txt);
    return num;
}

//排序
void bubble_sort(GoodsList* L)
{
    int len = 0;
    GoodsList* cur = L->next;
    for (; cur != NULL; cur = cur->next)
        len++;
    for (int i = 0; i < len; i++) {
        int cnt = 0;
        for (cur = L->next; cur->next != NULL; cur = cur->next) {
            cnt++;
            if (cnt == len - i - 1)
                break;
            if ((cur->data).goods_price > ((cur->next)->data).goods_price) {
                int tmp = (cur->data).goods_price;
                (cur->data).goods_price = ((cur->next)->data).goods_price;
                ((cur->next)->data).goods_price = tmp;
            }
        }
    }
}

//读商品信息
GoodsInfo read_goods_info()
{
    GoodsInfo goods;
    read_line(goods.goods_id, MAX_ID_LEN);
    read_line(goods.goods_name, MAX_NAME_LEN);
    scanf("%d", &goods.goods_price);
    read_line(goods.goods_discount, MAX_PRICE_LEN);
    scanf("%d", &goods.goods_amount);
    scanf("%d", &goods.goods_remain);
    return goods;
}