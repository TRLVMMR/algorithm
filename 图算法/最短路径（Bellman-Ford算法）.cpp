/*
	此算法可用于解决负权边

	如果一个图没有负权回路，那么最短路径所包含的边最多为n-1条。即n-1轮松弛后最短路不会再发生变化。
	如果n-1轮后仍发生变化，该图必然存在负权回路
*/

#include<stdio.h>
#define INF 65536

int main()
{
	int i=1,k,n,m=-1; 
	int v[10],u[10],w[10],dis[10];//dis为1到各各顶点的最短路程
	int flag=0,check;

	printf("请输入顶点个数");
	scanf("%d",&n);

	do 
	{
		printf("输入哪到哪，以及权值，输入p结束");
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		
		i++;
		m++;//存储边的数目
	}while('p' != getchar());//输入p时，还是在scanf语句，所以m++还是执行，之后%d不接受字符型，所以getchar从缓存队列里接受到p消息接受
		
	//初始化dis数组
	for(i=1;i<=n;i++)
		dis[i] = INF;
		dis[1] = 0;

	//Bellman-Ford核心语句：把u[i]->v[i]这条边当做中转站，寻找1点到各站的最短路程
	for(k=1;k<=n-1;k++)//最多执行n-1次，就能对所有边进行松弛
	{
		check = 0;
		for(i=1;i<=m;i++)
			if(dis[v[i]] > dis[u[i]] + w[i])//w[i]为u[i]->v[i]的权值（路程）
			{
				dis[v[i]] = dis[u[i]] + w[i];
				check = 1;
			}
		if(0 == check)//如果数组dis没有更新，退出循环
			break;
	}
	for(i=1;i<=m;i++)
		if(dis[v[i]] > dis[u[i]] + w[i])
			flag = 1;//用于标记是否存在负权边

	if(1 == flag)
			printf("该图含有负权边，不存在最短路径");
	else
	{
	for(i=1;i<=n;i++)
		printf("%d	",dis[i]);
	}

	getchar();
	getchar();
	return 0;
}