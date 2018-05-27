#include<stdio.h>
#define INF 65536

int main()
{
	int n,m,i=0,j,k;
	int u[8],v[8],w[8];
	int first[6],next[8];
	int dis[6] = {0},book[6] = {0};
	int que[101] = {0},head = 1,tail = 1;
	
	printf("输入顶点数\n");
	scanf("%d",&n);

	//初始化dis数组
	for(i = 1; i <= n; i++)
		dis[i] = INF;
	dis[1] = 0;

	//初始化book数组
	for(i = 1; i <= n; i++)
		book[i] = 0;

	//初始化first数组下标1-n为-1，即没有边
	for(i = 1; i <= n; i++)
		first[i] = -1;

	printf("读入边，请输入两个顶点跟权值，按p结束输入\n");
	do
	{
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		next[i] = first[u[i]];
		first[u[i]] = i;
	
	}while('p' == getchar());

	return 0;
}