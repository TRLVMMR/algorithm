/*
	核心：从i到j把其中一个站当中转站，从而找到最短路程	
	创建时间：2017年10月8日11:36:51
	更新时间：2017年10月8日11:37:04
*/
#include<stdio.h>
#define INF 65536


int main()
{
	int i,j,k,a,b,c;
	int n,e[51][51];
	
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

	//floyd-warshall算法核心语句：从i号到j号顶点把k当中转站的最短路程
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(e[i][j] > e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];

	//输出最终的结果，把整个表打印出来
	for(i =1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%10d",e[i][j]);//规定最少有10个字符宽度
		}
		printf("\n");
	}
	return 0;
}