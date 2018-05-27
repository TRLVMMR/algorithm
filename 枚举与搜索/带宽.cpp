#define LOCAL
#include<stdio.h>
#include<math.h>
#include<time.h>

int G[10][10],flag[10][10],n;
int dis[10],dmin[10];
int b[10],min = 9999;//b为各点到相邻点的最大值，b里的最大值即为带宽

int seach(int x,int y)
{
	int add = 0,add1 = 0;
	for(int i = 1; i <= n; i++)
	{
		if(dis[i] == x)
		{
			add = i;
		}
		if(dis[i] == y)
		{
			add1 = i;
		}
	
	}

	return abs(add - add1);
}

//找到此排列的带宽
int bmax()
{
	int i,j,k;
	//遍历图，找到i结点邻边点j的距离
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <=n; j++)
			{
				if(G[i][j] == 1)
				{
					//计算排列中i到j的距离，
					k = seach(i,j);

					//若大于已经计算过的带宽，就更新此点带宽b[i]
					 if( k > b[i])
					 {
						b[i] = k;
					 }
				}
			}
		}
		
		//遍历b[i]，找到最大的b[i]作为此排列的带宽
		int max = b[1];

		for(i = 1; i <= n; i++)
		{
			if(b[i] > max)
				max = b[i];
		
		}
		
		//重新初始化b[i]
		for(i = 1; i <= n; i++)
		{
			 b[i] = 0;
		}

		return max;
}

void line(int cur,int sum)
{
	int i;
		
	dis[sum]  = cur;

	if(sum > n)
	{
		
		int max = bmax();

		//如果比已知所有排列的最先带宽min小，则更新min值，并更新得到min值的排列dmin
		if(max < min)
		{
			min = max;
			for(i = 1; i <= n; i++)
			{
				dmin[i] = dis[i];
			}
			
		}
		return;
	}

	for(i = 1; i <= n; i++)
	{
		//如果当前节点到i能走，就走
		if(G[cur][i] == 1 && flag[cur][i] == 0)
		{	
	
			flag[cur][i] = 1;
			flag[i][cur] = 1;
			line(i,sum+1);
			flag[cur][i] = 0;
			flag[i][cur] = 0;
		}
	
	}


}

int main()
{
	int m,i,j,k;
	//输入重定向到带宽txt
#ifdef LOCAL
	freopen("带宽.in","r",stdin);
#endif
	//如果想手动输入，注释掉LOCAL的定义，执行以下程序
#ifndef LOCAL
	printf("请输入顶点数跟边数\n");
	printf("然后输入各条边的情况\n");
#endif 
	scanf("%d %d",&n,&m);


	for(i = 0; i < m; i++)
	{
		scanf("%d %d",&j,&k);
		G[j][k] = 1;
		G[k][j] = 1;
	}

	line(1,1);

	printf("最小带宽是%d\n",min);
	for(i = 1; i <= n; i++)
	{
		printf("%c ",dmin[i]+'A'-1);
	}
	printf("\n");

	printf("Time used = %.3fs\n",(double)clock() / CLOCKS_PER_SEC);

	return 0;
}