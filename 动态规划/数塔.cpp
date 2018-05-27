/*
	数塔第n层有n个数，每个数有两个孩子，相邻两个数有同一个孩子
*/
#include<stdio.h>

int max(int i,int j)
{
	return i > j ? i:j;
}

int main()
{
	int f[256][256],dp[256][256];
	int n;

	printf("输入数塔层数");
	scanf("%d",&n);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			scanf("%d",&f[i][j]);

		//边界：最后一层中dp的数值等于他们自身
	for(i = 1; i <= n; i++)
		dp[n][i] = f[n][i];

	for(i = n-1; i >= 1; i--)//从倒数第二层开始
	{
		for(int j = 1; j <= i; j++)
			dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + f[i][j];//下面一层的左边或者右边最大的一个加加上此点的权值，记录为此点最大权值
		//状态转移方程：dp[i][j] = max{dp[i+1][j],dp[i+1][j+1]}+f[i][j]
	}
	
	printf("%d\n",dp[1][1]);

	return 0;
}