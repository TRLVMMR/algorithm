#include<stdio.h>
#define IMPOSSIBLE 65536

int book[256], e[256][256],n,sum;

void dfs(int cur)
{
	int i;//每访问一个节点。sum就加1
	//if(cur >= n) return;//出现的问题是当前访问顶点永远不会超过n

	sum++;

	if(sum >= n) return;
	else
	{
		for(i=0;i<n;i++)
		{
			//出现一个问题，到2时发现0已经走过了。所以2-》0这条路不会打印
			if(1 == e[cur][i] && 0 == book[i] ||  1 == e[i][cur] && 0 == book[i])
			{
			if (1 == e[cur][i] && 0 == book[i])
			{
			
				printf("v%d-->v%d\n",cur,i);
				//从i节点开始访问下一个节点，最终会退回来
			}
			if(1 == e[i][cur] && 0 == book[i])
			{
			
				printf("v%d<--v%d\n",cur,i);
			}
			book[i] = 1;
			dfs(i);
			}
		}
	}
	return;
}


int main()
{
	int i,j,a,b;

	
	printf("请输入顶点数:");
	scanf("%d",&n);

	//初始化邻接矩阵
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i==j) e[i][j] = 0;
			else e[i][j] = IMPOSSIBLE;

	//构建邻接矩阵
	printf("输入p停止输入,");

	while('p' != getchar())
	{
	printf("输入顶点到顶点，中间用空格隔开：");
	scanf("%d %d",&a,&b);
	e[a][b] = 1;
	}

	//深度优先遍历
	book[0] = 1;//标记第0号节点已走过
	dfs(0);//从0号节点开始

	getchar();
	getchar();
	return 0;
}