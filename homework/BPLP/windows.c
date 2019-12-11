#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>


/*
1.绘制游戏界面
2.随机生成数字
1.从剩余空位中随机生成
3.移动数字
4.判断输赢
*/


int score;//得分
int best;//最高分
int board[4][4];
int x[16];//存储随机数的横坐标
int y[16];//存储随机数的纵坐标
int xNum;//随机数横坐标个数
int yNum;//随机数纵坐标个数
//游戏界面
void welcome()
{
system("cls");//每次输出前都要清屏
printf("得分:%4d 最高分:%4d\n\n",score,best);
printf("┌──┬──┬──┬──┐\n");
for(int i=0;i<4;i++)
{
printf("│");
for(int j=0;j<4;j++)
{
if(board[i][j]==0)//判断该位置有无数字
{
printf("    │");
}
else
{
printf("%4d│",board[i][j]);
}
}
if(i<3)
{
printf("\n├──┼──┼──┼──┤\n");
}
else//打印最后一行
{
printf("\n└──┴──┴──┴──┘\n");
}
}
}


//生成随机数
void randnum()
{
srand((unsigned)time(NULL));//生成随机种子


for(int i=0;i<4;i++)
{
for(int j=0;j<4;j++)
{
if(board[i][j]==0)
{
x[xNum++]=i;
y[yNum++]=j;
}
}
}//将可以生成随机数的位置记录下来

int a=rand()%xNum;
int b=a;//随机获取数组的下标



if((x[a]+y[b])%2==0)//百分之五十的几率给出2和4
{
board[x[a]][y[b]]=2;
}
else
{
board[x[a]][y[b]]=4;
}




xNum=0;
yNum=0;//等同于清空数组
}


//移动数字
void move()
{
/*
1.用上下左右,wsad来获取移动方向
2. 对上进行分析，当按下w键时，从上到下遍历board，当board[i][j]!=0且board[i-1][j]==0且i不出界,board[i-1][j]=board[i][j]且board[i][j]=0;当board[i][j]!=0且board[i-1][j]==board[i][j]且i不出界,board[i-1][j]+=board[i][j],board[i][j]==0;
3.对下进行分析，当按下s键时，从下到上进行遍历board,当board[i][j]!=0且board[i+1][j]==0,board[i+1][j]=board[i][j]且board[i][j]=0
4.左和右同理
*/
int i,j;
char ch;
ch=getch();
switch(ch)
{
case 'w':
for(i=0;i<4;i++)
{
for(j=0;j<4;j++)
{
if(board[i][j]!=0&&i-1>=0&&board[i-1][j]==0)//当该位置有数字，且该位置上面的位置无数字
{
board[i-1][j]=board[i][j];
board[i][j]=0;
}
else if(board[i][j]!=0&&i-1>=0&&board[i][j]==board[i-1][j])//当该位置有数字，且该位置上面的位置与该位置相同
{
board[i-1][j]+=board[i][j];//两数相加
board[i][j]=0;
}
}
}
break;
case 's':
for(i=3;i>=0;i--)
{
for(j=0;j<4;j++)
{
if(board[i][j]!=0&&i+1<4&&board[i+1][j]==0)//同上
{
board[i+1][j]=board[i][j];
board[i][j]=0;
}
else if(board[i][j]!=0&&i+1<4&&board[i][j]==board[i+1][j])
{
board[i+1][j]+=board[i][j];
board[i][j]=0;
}
}
}
break;
case 'a':
for(i=0;i<4;i++)
{
for(j=0;j<4;j++)
{
if(board[j][i]!=0&&i-1>=0&&board[j][i-1]==0)//同上
{
board[j][i-1]=board[j][i];
board[j][i]=0;
}
else if(board[j][i]!=0&&i-1>=0&&board[j][i]==board[j][i-1])
{
board[j][i-1]+=board[j][i];
board[j][i]=0;
}
}
}
break;
case 'd':
for(i=3;i>=0;i--)
{
for(j=0;j<4;j++)
{
if(board[j][i]!=0&&i+1<=3&&board[j][i+1]==0)//同上
{
board[j][i+1]=board[j][i];
board[j][i]=0;
}
else if(board[j][i]!=0&&i+1<=3&&board[j][i]==board[j][i+1])
{
board[j][i+1]+=board[j][i];
board[j][i]=0;
}
}
}
break;
}
}


int main()
{
while(1)//不断打印
{
welcome();
randnum();
move();
}
return 0;
}