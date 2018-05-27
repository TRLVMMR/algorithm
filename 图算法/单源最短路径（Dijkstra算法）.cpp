#include<stdio.h>
#define INF 65536

int main()
{
	int i,j,k,a,b,c,u,v,min;//从u顶点到v顶点
	static int n,e[51][51],book[51],dis[51];//静态数组初始化为0，dis数组存放1号顶点到各个顶点的路程
	
	printf("请输入顶点数:");
	scanf("%d",&n);

	//初始化邻接矩阵
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j] = 0;
			else e[i][j] = INF;

	printf("输入p停止输入\n");

	//读入边
	while('p' != getchar())
	{
		printf("输入顶点到顶点已及权值，中间用空格隔开：");
		scanf("%d %d %d",&a,&b,&c);
		e[a][b] = c;
	}

	//初始化dis数组
	for(i=1;i<=n;i++)
		dis[i] = e[1][i];

	book[1] = 1;

	//Dijkstra算法核心语句
	for(i=1;i<=n-1;i++)//走到最后一个的时候，就算把最后一个值当中转，他后面也没有值了，所以不需要走到最后一个，n-1即可
	{//这里的i什么也不表示，只是用来控制循环次数的一个变量
		min = INF;//每次都要赋予无穷，因为要选出后面几个的最小值，不每次赋予无穷的话上次的最小值肯定比较小
		//找到离1点最近的点
		for(j=1;j<=n;j++)
		{
			if(0 == book[j] && min > dis[j])
			{
				min = dis[j];
				u = j;//u点就是最近的点
			}
		}
		
		book[u] = 1;//标记最近的点已经确定，方便下次找排除这点外离1点最近的点
		//把最近的点当中转点，如果近就修改值
		for(v=1;v<=n;v++)
		{
			if(dis[v] > dis[u] + e[u][v])//再次提醒，dis[u]为已知1到u的最短路程
				dis[v] = dis[u] + e[u][v];
			//if(e[1][v]>e[1][u]+e[u][v])不行，因为dis用来记录已经走过的最短路程，这样写只能134,123，这样三个三个的，运用不了之前已计算的路径
			//	dis[v] = e[1][u]+e[u][v];因为可能最短路程是123456，
			//即用dis会记录之前的值，用e[1][u]
		}

	}

		for(i=1;i<=n;i++)
			printf("%d ",dis[i]);

		getchar();
		getchar();
	return 0;
}