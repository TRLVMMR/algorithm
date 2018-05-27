#include<stdio.h>
#define IMPOSSIBLE 999999

int min = 9999999,book[101],n,e[101][101];

void dfs(int cur,int dis)
{
	int i;
	if(dis > min)  return;//如果已经走过的路程比最小路程还长那么就没必要继续走下去了
	
	if(cur == n)//走到n，记录路线长度
	{
		if(dis < min)//找到比最小值还短的路线，更新最小值
		min = dis;
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(e[cur][i] != IMPOSSIBLE && 0 == book[i] )
		{
			book[i] = 1;
			dfs(i,dis+e[cur][i]);
			book[i] = 0;
		}
	
	}


	return;
}

int main()
{
	int i,j,a,b,c;

	printf("输入顶点数");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if (i == j)  e[i][j] = 0;
			else e[i][j] = 	IMPOSSIBLE;

	while('p' != getchar())
	{
		printf("输入从哪到哪点，以及权值，输入p结束");
		scanf("%d %d %d",&a,&b,&c);
		e[a][b] = c;
		
	}


	book[1] = 1;
	dfs(1,0);
	printf("%d",min);

	getchar();
	getchar();

	return 0;
}