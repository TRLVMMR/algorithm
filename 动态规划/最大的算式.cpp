/*
	每个数只考虑与下一个数的结合情况
	如果dp[i][j]为,i到j计算结果的最大值,在计算dp[i][j]时，要用dp哪到哪进行计算
	
	
	枚举最后一次乘法(加法区间):使用sum数组, 枚举所有可能性 


*/
#include<iostream>
#include<algorithm>

using namespace std;

long long dp[20][20];
long long sum[20];//到i为止的数相加的和 



int main()
{
	int n, k;
	
	cin >> n >> k;
	
	//从1开始的好处：由于需要用到i-1，从1开始不必要写特殊情况 
	for(int i = 1; i <= n; i++)
	{
		long long temp;	
		cin >> temp;
		sum[i] = sum[i-1] + temp;
		//边界为全都加 
		dp[i][0] = sum[i];
	}
	
	for(int i = 1; i <= n; i++)
	{
		//运算符个数 = 数字个数 - 1，所以最大有i-1个
		int right = min(i - 1, k);
		for(int j = 1; j <= right; j++)
		{
			//枚举最后一次乘法,加法区间为[x, i],  x-1意味着x必须大于1, 但如果用到加法，至少是一个乘法一个加法 
			for(int x = 2; x <= i; x++)
			{
				dp[i][j] = max(dp[i][j], dp[x - 1][j - 1] * (sum[i] - sum[x - 1]));
			} 
		}
	}
	
	cout << dp[n][k];
	
	return 0;
} 
