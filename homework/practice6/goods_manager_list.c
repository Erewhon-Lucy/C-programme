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

typedef struct {
	char    goods_id[MAX_ID_LEN];
	char    goods_name[MAX_NAME_LEN];
	int     goods_price;
	char    goods_discount[MAX_DISCOUNT_LEN];
	int     goods_amount;
	int     goods_remain;
} GoodsInfo;

typedef struct node
{
	GoodsInfo data;
	struct node *next;
} GoodsList;



//全局变量，存储当前商品的数量
int CurrentCnt;

//-------------------------------------------------------------
//初始化链表
//参数：链表指针的指针
//-------------------------------------------------------------
void init_list(GoodsList **L) {
	//从文件goodsinfo.txt中读入数据
	//把你的代码添加在这里

	printf("商品的链表文件已建立，有%d个商品记录\n", CurrentCnt);
}

//-------------------------------------------------------------
//以行读取输入的信息
//-------------------------------------------------------------
int read_line(char str[], int n)
{
	int ch, i = 0;

	while (isspace(ch = getchar()))
		;
	while (ch != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}

GoodsInfo read_goods_info(){
	GoodsInfo goodsInfo;

	//在这个函数中从键盘读入一个goods的数据
	//如果是字符串，请调用read_line
	//把你的代码添加在这里

	return goodsInfo;
}

//-------------------------------------------------------------
//添加一条商品记录
//-------------------------------------------------------------
bool insert_item(GoodsList *L, GoodsInfo goodsInfo, int choice) {
	//在链表*L中添加一个记录goodsinfo
	//choice指明了添加位置
	//把你的代码添加在这里
}


//-------------------------------------------------------------
//删除一条商品记录
//-------------------------------------------------------------
bool delete_item(GoodsList *L, char* goods_id) {
	//在链表中删除指定ID号的记录
	//把你的代码添加在这里
	//提示：先找到ID号记录在哪里
}


//-------------------------------------------------------------
//查找一条商品记录
//返回值：指向找到的记录的指针
//-------------------------------------------------------------
GoodsList* search_item(GoodsList *L, char* goods_id) {
	//在链表中查找指定ID号的记录
	//把你的代码添加在这里
}

//-------------------------------------------------------------
//修改一条商品记录
//-------------------------------------------------------------
bool change_item(GoodsList *L, char* goods_id, GoodsInfo new_info) {
	//修改链表中的指定记录
	//先查找指定ID号的记录，然后再用new_info替换它
	//把你的代码添加在这里
}


//-------------------------------------------------------------
//打印单个商品链表节点的信息
//按指定格式打印一条记录的信息
//-------------------------------------------------------------
void output_one_item(GoodsList *p){
	printf("ID:%s\t名称:%s\t价格:%3d\t折扣:%s\t数量:%d\t剩余:%d\n",
	       //把你的代码添加在这里
		);
}


//-------------------------------------------------------------
//在屏幕上输出所有商品信息
//-------------------------------------------------------------
void output_all_items(GoodsList *L)
{
	//把你的代码添加在这里
}

//-------------------------------------------------------------
//释放商品链表
//-------------------------------------------------------------
void destory_list(GoodsList **L) {
	//把你的代码添加在这里
}


//-------------------------------------------------------------
//删除商品文件以及商品链表中的所有信息
//-------------------------------------------------------------
void destory_list_and_file(GoodsList **L) {
	//把你的代码添加在这里
	//删除文件用remove函数
}

//-------------------------------------------------------------
//将当前商品链表中的内容存入商品文件goodsinfo.txt，返回商品的个数
//-------------------------------------------------------------
int save_to_file(GoodsList *L) {
	//把你的代码添加在这里
}

//--------------------------------------------------------------------
//冒泡排序实现对链表节点的排序，对价格从低到高排序
//--------------------------------------------------------------------
void bubble_sort(GoodsList *L) {
	//把你的代码添加在这里
}

int main(void)
{
	GoodsList *goodsList;
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
