#include<stdio.h>

int max(int x,int y)
{
	if(x > y)
		return x;
	else
		return y;
	//return x > y ? x : y;
}

int main()
{
	int A[256],dp[256];
	int n,ans = -1;

	printf("请输入n的数值");
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d",&A[i]);

	
	
	for(i =1; i <= n; i++)
	{	
		dp[i] = 1;//初始化条件，假设每个元素自成子序列
		for(int j = 1; j < i; j++)//遍历i前的所有元素，存在i前的元素比i小，且长度
		{
			if(A[i] >= A[j] && dp[j] +1 > dp[i])//把前面的元素中最长的dp+1给dp[i]
												//记录每次到这个点为止的最长度，如果有更长就把长的给dp[i]
			{
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans,dp[i]);//每次记录最长的，在这里加的目的是等下不用再去遍历一次
	}

	printf("%d\n",ans);

	return 0;
}