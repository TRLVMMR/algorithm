/*
	2017年10月12日23:50:02
	时间复杂度为O(N^2)，借助堆，复杂度变为O(logM)，再用邻接表变为O(MlogN)
*/
#include<stdio.h>
#define INF 65536

int main()
{
	int n,i,j,k,min,t1,t2,t3;
	int e[7][7],dis[7],book[7]={0};
	int count = 0,sum = 0;

	printf("请输入顶点数");
	scanf("%d",&n);
	
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j] = 0;
			else	e[i][j] = INF;

		
	do
	{
		printf("请输入从哪到哪以及权值,输入p结束");
		scanf("%d %d %d",&t1,&t2,&t3);
		e[t1][t2] = t3;
		e[t2][t1] = t3;

	}while('p' != getchar());

	for(i=1;i<=n;i++)
		dis[i] = e[1][i];
	
	//Prim算法开始
	book[1] = 1;
	count++;

	while(count < n)
	{
		min = INF;
		for(i=1;i<=n;i++)
		{
			if(0 == book[i] && dis[i] < min)
			{
				min = dis[i];
				j = i;
			}
		}
		
		book[j] = 1;
		count++;
		sum = sum + dis[j];

		for(k=1;k<=n;k++)
		{
			if(0 == book[k] && dis[k] > e[j][k])
				dis[k] = e[j][k];
		
		}
	
	
	}

	printf("%d",sum);

	getchar();
	getchar();
	return 0;
}