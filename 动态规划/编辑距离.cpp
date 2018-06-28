/*
	定义状态：
		dp[i][j]为字符串str1的前i个字符，到str2的前j个字符的最短距离 
		
	状态转移：
		两个字符串相等时：
			相等：dp[i][j] = dp[i-1][j-1]
		不等时： 
			插入：dp[i][j] = dp[i][j-1] + 1  		//此时, i < j, 使用插入的i 
			删除: dp[i][j] = dp[i-1][j] + 1  		//此时，i > j，  i-1与j达到同长 
			替换：dp[i][j] = dp[i-1][j-1] + 1 		//此时  i == j,
		边界：
			从空字符串""到str，插入i次, 
			dp[i][0] = i
			dp[0][j] = j 
		
	注意：字符串是从0开始的，而0行0列考虑的是空字符串 
		 
*/
#include<iostream>
#include<string>
#include<algorithm> 
#define MAXV 256

using namespace std;

string str1, str2;
int dp[MAXV][MAXV];


int distance()
{
	int len1 = str1.length();
	int len2 = str2.length();
	 
	for(int i = 0; i <= len1; i++)
		dp[i][0] = i;
	for(int j = 0; j <= len2; j++)
		dp[0][j] = j;
	
	for(int i = 1; i <= len1; i++)
	{
		for(int j = 1; j <= len2; j++)
		{
			if(str1[i - 1] == str2[j - 1])
			{
				dp[i][j] = dp[i - 1][j - 1];
			}
			else
			{
				dp[i][j] = min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1])) + 1;
			}
			
		}
		
	}
	
	for(int i = 0; i <= len1; i++)
	{
		for(int j =0; j <= len2; j++)
			cout << dp[i][j] << " ";
		cout << endl;	
	}
	
	return dp[len1][len2];
}


int main()
{
	cin >> str1 >> str2;
	
	cout << distance() << endl;
	
		
	
	return 0;
} 
