#include<stdio.h>
#define  INF 65536

int pre[50];

void dfs(int i)
{
	if(pre[i] == i)
		return;

	dfs(pre[i]);
	printf("%d ",pre[i]);

}

int main()
{
	int n,m,i,j,k,w,min,cur,s;
	int G[50][50],dis[50],flag[50] = {0};

	printf("输入顶点数以及边数");
	scanf("%d %d",&n,&m);

	//初始化邻接矩阵
	for(i = 1; i <= n; i++)
		for(j = 1;j <= n; j++)
			if(i == j)	G[i][j] = 0;
			else		G[i][j] = INF;

	//初始化dis数组与pre数组
	for(i = 1; i <= n; i++)
	{
		dis[i] = G[1][i];
		pre[i] = i;
	}
		

	for(i = 1; i <= m; i++)
	{
		scanf("%d %d %d",&j,&k,&w);
		G[j][k] = w;
	
	}


	//Dijkstra
	for(i = 1; i <= n ; i++)//若前面有flag[1] = 1;则只需n-1轮松弛
	{
		min = INF;
		//找到除了访问过的，剩下离起点最近的点
		for(j = 1; j <= n; j++)
		{
			if(flag[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				cur = j;

			}
		
		}

		flag[cur] = 1;
		//pre[cur] = 前驱;
		//问题：pre在这里记录前驱结点会不会比较好？只需要改变一次
		//在这里改的话 ，你需要知道它的前驱是谁。。。
		for(j = 1; j <= n; j++)
		{
			if(flag[j] == 0 && G[cur][j] < INF && dis[cur] + G[cur][j] < dis[j])//G[cur][j] < INF 此句忘记了，其实没有也能正常运行
			{												//松弛阶段判断flag是否为1,有没有都行
				dis[j] = dis[cur] + G[cur][j];
				pre[j] = cur; 
				//问题：pre在这里更新不会因为太多个在遍历事产生错误么？
				//正因为多次修改（松弛），最终才找到最小的那个前驱
			}
		}
	}

	for(i = 1; i<= n; i++)
		printf("%d ",pre[i]);


	scanf("%d",&s);
	dfs(s);
	printf("%d\n",s);
//无法知道终点是哪一个？终点是我们输入的

	return 0;
}
