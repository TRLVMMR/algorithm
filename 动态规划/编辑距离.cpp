/*
	����״̬��
		dp[i][j]Ϊ�ַ���str1��ǰi���ַ�����str2��ǰj���ַ�����̾��� 
		
	״̬ת�ƣ�
		�����ַ������ʱ��
			��ȣ�dp[i][j] = dp[i-1][j-1]
		����ʱ�� 
			���룺dp[i][j] = dp[i][j-1] + 1  		//��ʱ, i < j, ʹ�ò����i 
			ɾ��: dp[i][j] = dp[i-1][j] + 1  		//��ʱ��i > j��  i-1��j�ﵽͬ�� 
			�滻��dp[i][j] = dp[i-1][j-1] + 1 		//��ʱ  i == j,
		�߽磺
			�ӿ��ַ���""��str������i��, 
			dp[i][0] = i
			dp[0][j] = j 
		
	ע�⣺�ַ����Ǵ�0��ʼ�ģ���0��0�п��ǵ��ǿ��ַ��� 
		 
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
