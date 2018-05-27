#include<stdio.h>
#include<algorithm>
#define INF 65536

int dp[256] = {0},flag[256];
int choice[256]={-1};//记录结点的后继（下一个）
int G[50][50],n;

int DP(int i)
{
	int j,temp;
	if(dp[i] > 0)	return dp[i];//如果dp[i]计算过
	
	for(j = 1; j < n; j++)
	{
		if(G[i][j] != INF)
		{
			//相当于max(dp[i],DP[j] + G[i][j])，但是为了记录后继，便分成两步
			temp = DP(j) + G[i][j];
			if(temp < dp[i])
			{
				dp[i] = temp;
				choice[i] = j;
				
			}
		}	
	}

	return dp[i];
}

//尾递归遍历结点
void PrintPath(int i)
{
	if(-1 == i)	return;//边界即循环的判断

	printf("->%d",choice[i]);
	PrintfPath(choice[i]);//相当于i = choice
	/*
	尾递归可换成
	while(choice[i] == -1)
	{
		i = choice[i];
		printf("->%d",i);//相当于递归在printf后递归，（循环在printf后才判断）
	}
	*/
}

int main()
{
	//需要把边界初始化

	return 0;
}