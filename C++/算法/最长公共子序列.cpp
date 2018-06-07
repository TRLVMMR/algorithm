/*
	最长公共子序列：
	 
		设有序列a, b， 公共子序列长度为k 
		使用搜索：
			将a字符串分成各种组合，可能性有C（alen - k）(alen)的可能性 再乘以blen的，复杂度相当高 
		使用dp：
			复杂度为alen * blen ， 因为alen每次加1，都要扫描一次b字符串 
		dp为什么使复杂度变低了：
			 
	
	
		状态：
			 dp[i][j]代表从a[i]为止， b[j]为止的最长公共子序列长度 
	
		最优子结构： 
					相等时，两个都要 
					1. dp[i-1][j-1] + 1   a[i] == b[j]
					
						不等时，舍弃其中一个，才有可能组成新的序列 
					2. dp[i][j-1]       a[i] != b[j]
						或dp[i-1][j] 
						
					3.最容易忽略的
						i = 0或j = 0时，dp = 0,即递归终点 
		 
		状态转移方程同上。
				
		 
	注意事项： dp边界是i = 0或j = 0时 
	i - 1等部分，i = 0时的问题 . 解决方法，从1开始 
		 
*/

#include<iostream>
#include<string>
#include<algorithm> 
#define MAXV 256

using namespace std;


int dp[MAXV][MAXV];

//粗略版，但能看出一定问题 
void maxPubLen()
{
	string a, b;
	
	cin >> a;
	cin >> b;
	
	int alen = a.length();
	int blen = b.length();
	 
	
	for(int i = 0; i < alen; i++)
	{
		for(int j = 0; j < blen; j++)
		{	
			//0位的特殊处理 
			if(i == 0 || j == 0)
			{
				dp[i][j] = 0;
				
				if(a[i] == b[j])
				{
					dp[i][j] = 1;
				}
				else
				{
					if(i != 0)
					{
						dp[i][j] = max(dp[i - 1][j], 0);
					}
					else if(j != 0)
					{
						dp[i][j] = max(dp[i][j - 1], 0);
					}
				}
				cout << dp[i][j]; 
				continue;
			}
			
			if(a[i] == b[j])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			
			cout << dp[i][j]; 
		}	
		cout << endl;
	}
} 

//上面的优化版 
void maxPublicLen()
{
		string a, b;
	
	cin >> a;
	cin >> b;
	
	int alen = a.length();
	int blen = b.length();
	 
	//初始化0行跟0列的数为0， 即i = 0或j = 0的条件 
	for(int i = 0; i < alen; i++)
	{
		dp[0][i] = 0;
		dp[i][0] = 0;
	}
	
	//为何要+1？因为1到alen+1才是字符串a的长度 
	for(int i = 1; i < alen + 1; i++)
	{
		for(int j = 1; j < blen + 1; j++)
		{	
			//字符串是从0开始的，算法导论的子序列是x1开始， 所以这句改一下就能够遍历所有字符串字符了  
			if(a[i - 1] == b[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}
			else
			{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
			
			cout << dp[i][j]; 
		}	
		cout << endl;
	}
	
	
} 
int main()
{
	

	
	/*
	int ans = 0;
	for(int i = 0; (i < a.length())&& (i < b.length()); i++)
	{
		for(int j = 0; (j < a.length())&& (j < b.length()); j++)
			ans = max(ans, dp[i][j]);
		
	}
	
	cout << ans << endl;*/
	
	return 0;
} 
