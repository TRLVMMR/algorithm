/*
	比起深度优先，广度优先遍历更合适于所有边权值相等的情况
	创建于2017.10.7
*/
#include<stdio.h>
#define INF 65536

struct note
{
	int x;//城市编号
	int s;//转机次数
};

int main()
{
	struct note que[256];//que数组用于存放start城市到各个城市的最小转机次数
	int e[51][51] = {0},book[51] = {0};
	int i,j,n,start,end,min,cur,flag=0;
	int head,tail;

	//初始化二维矩阵
	printf("请输入城市个数");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j] = 0;
			else e[i][j] = INF;

	while('p' != getchar())
	{
		printf("请输入城市哪到哪,输入p结束输入");
		scanf("%d %d",&i,&j);
		if(i <= n && j <= n)
		{
		e[i][j] = 1;
		e[j][i] = 1;//这里是无向图
		}
		else
			printf("您输入的数值太大，请重新输入");
	}
	
	head = 1;
	tail = 1;

	printf("输入开始城市跟目的地城市的编号，中间用空格隔开");
	scanf("%d %d",&start,&end);


	//从start号城市出发，将start城市加入队列
	que[tail].x = start;
	que[tail].s = 0;
	tail++;
	book[start] = 1;


	while(head < tail)
	{
		cur = que[head].x;//cur为当前城市编号
	//	if(min > note[cur])
	//		min = note[cur];//不需要用最小值，因为一扩展到目标城市，que数组储存的肯定是最小值
		for(i=1;i<=n;i++)
		{
			if(1 == e[cur][i] &&0 == book[i])
			{
				book[i] = 1;
				que[tail].x = i;//将跟当前能转机的城市编号放入队列
				que[tail].s = que[head].s + 1;//转机次数加一
					tail++;
			}
			if(tail-1 == end)//必须放到for循环里，否则可能tail走远了
			{
				flag = 1;
				break;
			}
		}

		if(1 == flag)
			break;
			head++;
	}


	printf("最小转机数为：%d",que[tail-1]);
	return 0;
}