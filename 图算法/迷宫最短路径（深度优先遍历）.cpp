#include<stdio.h>


int m,n,p,q,min = 9999999;//p,q为终点坐标,n,m为迷宫的长宽
int a[256][256],book[256][256];

void dfs(int x,int y,int step)
{	//x是上下，y是左右。。。傻逼作者
	int next[4][2] = {{0,1},//右
						{1,0},//下
						{0,-1},//左
						{-1,0}};//上

	int tx,ty,k;

	if(x == p && y == q)//到达终点
	{
		//如果有步数更少的，更新min的值
		if(step < min)
			min = step;
		return;
	}

	for(k=0;k<=3;k++)//尝试下一步
	{
		tx = x + next[k][0];
		ty = y + next[k][1];
		//判断是否越界
		if(tx > n || tx<1 || ty > m||ty <1)
			continue;
		//判断是否是障碍物或者走过的路
		if(0 == a[tx][ty] && 0 == book[tx][ty])
		{
			book[tx][ty] = 1;//走过这个点
			dfs(tx,ty,step+1);//走向下一个点
			book[tx][ty] = 0;//每次递归消除上一个点，进行其他路线的测试

		}
	
	}

	return;
}
int main()
{
	int i,j,startx,starty;

	printf("请输入迷宫的长度跟宽度，中间用空格隔开\n");
	scanf("%d %d",&n,&m);

	//读入迷宫

	printf("用1表示障碍物，0表示空地，输入迷宫\n");
	for(i=1;i<=n;i++)
		//printf("\n");
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);

	//输入起点跟终点坐标

	printf("输入起点和终点坐标\n");
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	
	//从起点开始搜索

	book[startx][starty] == 1;//标记起点，防止重复走
	dfs(startx,starty,0);//初始化步数为0

	//输入最短步数

	printf("最短步数为：%d\n",min);
	getchar();
	getchar();

	return 0;
}