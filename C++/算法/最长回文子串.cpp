/*
	����dp 
*	˼·1
 	״̬:dp[i][j]������־�ַ���i��j�Ƿ�Ϊ���Ĵ� 
	
	

	 
	�����ӽṹ��dp[i][j] = dp[i+1][j-1] (i == j)
				dp[i][j] = false             (i != j)
				
		���Ĵ���ʼ״̬�е��������ż����� 
	�߽磺1. �������:i == j
				dp[i][j] = true
		 2  ż�������j - i = 1 
				dp[i][j] = true    (i == j)
				dp[i][j] = false   (i != j)


	
*	˼·2��
	״̬��dp[i][j]������¼���Ĵ��ĳ���
	
	 �����ӽṹ��
	 		dp[i][j] = dp[i+1][j-1] + 2    (i == j) ��dp[i+1][j-1]�ǻ��Ĵ� 
			dp[i][j] =  0					(i != j)
			�����Ļ���ֻ����i==j����ʱ�Ż����������ӣ�i��=j��һֱ�����ǻ��Ĵ�
	�߽磺
	��������� 
		dp[i][j] = 1  (i == j)
	ż�����:
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
	
	//������Ч�ʣ����ǿɶ�����д�� 
	//ö�����䳤��, �ô���֧��i��jͬʱ�Ķ�������һ��ѭ��һ�θĶ� 
	for(int L = 1; L <= len; L++)
	{	
		//L = 1��L = 2��Ϊ��ʼ������ 
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
		//��ʽ��ʼ״̬ת�� 
		else
		{ 
			//i��ȡֵ��Χ����д�� 
			for(int i = 0; i <= len - L; i++)
			{
				int j = i + L - 1;
				if(str[i] == str[j])
				{
					//i + 1����д��i -1  
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
	
	//������Ч�ʣ����ǿɶ�����д�� 
	//ö�����䳤��, �ô���֧��i��jͬʱ�Ķ�������һ��ѭ��һ�θĶ� 
	for(int L = 1; L <= len; L++)
	{	
		//L = 1��L = 2��Ϊ��ʼ������ 
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
		//��ʽ��ʼ״̬ת�� 
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
