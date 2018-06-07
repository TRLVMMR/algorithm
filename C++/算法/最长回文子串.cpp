/*
	区间dp 
*	思路1
 	状态:dp[i][j]用来标志字符串i到j是否为回文串 
	
	

	 
	最优子结构：dp[i][j] = dp[i+1][j-1] (i == j)
				dp[i][j] = false             (i != j)
				
		回文串初始状态有单数情况跟偶数情况 
	边界：1. 单数情况:i == j
				dp[i][j] = true
		 2  偶数情况：j - i = 1 
				dp[i][j] = true    (i == j)
				dp[i][j] = false   (i != j)


	
*	思路2：
	状态：dp[i][j]用来记录回文串的长度
	
	 最优子结构：
	 		dp[i][j] = dp[i+1][j-1] + 2    (i == j) 且dp[i+1][j-1]是回文串 
			dp[i][j] =  0					(i != j)
			这样的话，只有在i==j成立时才会有数字增加，i！=j就一直代表不是回文串
	边界：
	单数情况： 
		dp[i][j] = 1  (i == j)
	偶数情况:
		dp[i][j] = 2  (i - j = 1 && i == j) 
		J
		
	
*/
#include<iostream>
#include<string>
#include<algorithm>
#define MAXV 256

using namespace std;

void frist_palindrome(const string& str)
{
	bool dp[MAXV][MAXV];
	int len = str.length();
	int maxlen; 
	
	//不考虑效率，考虑可读性来写的 
	//枚举区间长度, 好处，支持i跟j同时改动，不用一个循环一次改动 
	for(int L = 1; L <= len; L++)
	{	
		//L = 1与L = 2均为初始化处理 
		if(L == 1)
		{
			for(int i = 0; i < len; i++)
			{
				dp[i][i] = true;
				maxlen = 1;	
			} 
			
		}
		else if(L == 2)
		{
			for(int i = 0; i <= len - L; i++)
			{
				if(str[i] == str[i + 1])
				{
					dp[i][i + 1] = true;
					maxlen = 2;
				}
				else
				{
					dp[i][i + 1] = false;
				}
			}
			
		}
		//正式开始状态转移 
		else
		{ 
			//i的取值范围经常写错 
			for(int i = 0; i <= len - L; i++)
			{
				int j = i + L - 1;
				if(str[i] == str[j])
				{
					//i + 1经常写成i -1  
					dp[i][j] = dp[i + 1][j - 1];
					if(dp[i + 1][j - 1])
					{
						maxlen = L;	
					}

				}
				else
				{
					dp[i][j] = false;
				}
			}
		}
	}
	
	
	cout << maxlen << endl;

	
}

void second_palindrome(const string& str)
{
	int dp[MAXV][MAXV];
	fill(dp[0], dp[0] + MAXV * MAXV, 0);

/*

	for(int i = 0; i < MAXV; i++)
	{
		for(int j = 0; j < MAXV; j++)
		{
			dp[i][j] = 0;
		}
	}
*/	
	int len = str.length(); 
	
	//不考虑效率，考虑可读性来写的 
	//枚举区间长度, 好处，支持i跟j同时改动，不用一个循环一次改动 
	for(int L = 1; L <= len; L++)
	{	
		//L = 1与L = 2均为初始化处理 
		if(L == 1)
		{
			for(int i = 0; i < len; i++)
			{
				dp[i][i] = 1;
			} 
			
		}
		else if(L == 2)
		{
			for(int i = 0; i < len - 1; i++)
			{
				if(str[i] == str[i + 1])
				{
					dp[i][i + 1] = 2;
				}
				else
				{
					dp[i][i + 1] = 0;
				}

			}
			
		}
		//正式开始状态转移 
		else
		{ 
			for(int i = 0; i <= len - L; i++)
			{
				int j = i + L - 1;
				if(str[i] == str[j])
				{
					if(dp[i + 1][j - 1])
						dp[i][j] = dp[i + 1][j - 1] + 2;
				}
				else
				{
					dp[i][j] = 0;
				}
			}

		}
	}
	
	int maxlen = 0;
	for(int i = 0; i < len; i++)
	{
		for(int j = 0; j < len; j++)
		{
			if(maxlen < dp[i][j])
			{
				maxlen = dp[i][j];	
			}	
			
		}
		
	}
	
	cout << maxlen << endl;
}


int main()
{
	string str;
	
	cin >> str;
	
	frist_palindrome(str);
	second_palindrome(str);
	
	return 0;
 } 
