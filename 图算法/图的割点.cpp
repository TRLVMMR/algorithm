/*
	
*/
#include<stdio.h>

int n,m,e[9][9],root,book[10];
int num[9],low[9],flag[9],index;//index用来进行时间戳的递增

int min(int x, int y)
{
	return x < y ? x : y;
}

/*
	不经过cur点i能到达的最早时间戳low[i]，比cur的时间戳还大num[cur]，那么只要割掉cur点，i点就回不去了	
*/
void dfs(int cur,int father)
{
	int child=0,i,j;
	
	index++;
	num[cur] = index;//当前顶点的时间戳
	low[cur] = index;//当前顶点能访问到最早顶点的时间戳，最开始是自己

	for(i = 1; i <=n; i++)
	{
		if(1 == e[cur][i])//经过的所有点
		{
			if(0 == num[i])//没访问的点肯定不是他父亲
			{	
				child++;
				dfs(i,cur);
				
				//	if(low[i] < low[cur])使用这个记录会出错，原因由于vc6无法调试未知
				//		low[cur] = low[i];

				
				low[cur] = min(low[cur],low[i]);//更新当前顶点cur能访问到的最小时间戳
												//每次执行完这步就已经意味cur更新完1到i为止的最小时间戳
				if(cur != root && low[i] >= num[cur])//i顶点能回到的最小时间戳比cur的时间戳大
					flag[cur] = 1;
				
				if(cur == root && child == 2)
					flag[cur] = 1;

			
			}
		else if(i!= father)//如果i顶点被访问过，且不是父亲，更新最小时间戳
		{	//以不更新经过父亲时间戳的行为来实现不经过父节点的行为，此最早时间戳可能不是最早，但只要
		//	if(low[i] < low[cur])
		//		low[cur] = low[i];
			low[cur] = min(low[cur],num[i]);//如果是low[i]可能i是经过父亲的
		}
		
		}
	
	
	}
}

int main()
{
	int i,j,x,y;

	printf("请输入顶点数：");
	scanf("%d",&n);

	do
	{
		scanf("%d %d",&x,&y);
		e[x][y] = 1;
		e[y][x] = 1;
	
	}while('p' != getchar());

	root = 1;//从1号顶点开始进行深度优先遍历

	dfs(1,root);

	for(i=1;i<=n;i++)
	{
		if(flag[i])
			printf("%d	",i);
	}

	getchar();
	getchar();
	return 0;
}