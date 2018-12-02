/*
	ÿ����ֻ��������һ�����Ľ�����
	���dp[i][j]Ϊ,i��j�����������ֵ,�ڼ���dp[i][j]ʱ��Ҫ��dp�ĵ��Ľ��м���
	
	
	ö�����һ�γ˷�(�ӷ�����):ʹ��sum����, ö�����п����� 


*/
#include<iostream>
#include<algorithm>

using namespace std;

long long dp[20][20];
long long sum[20];//��iΪֹ������ӵĺ� 



int main()
{
	int n, k;
	
	cin >> n >> k;
	
	//��1��ʼ�ĺô���������Ҫ�õ�i-1����1��ʼ����Ҫд������� 
	for(int i = 1; i <= n; i++)
	{
		long long temp;	
		cin >> temp;
		sum[i] = sum[i-1] + temp;
		//�߽�Ϊȫ���� 
		dp[i][0] = sum[i];
	}
	
	for(int i = 1; i <= n; i++)
	{
		//��������� = ���ָ��� - 1�����������i-1��
		int right = min(i - 1, k);
		for(int j = 1; j <= right; j++)
		{
			//ö�����һ�γ˷�,�ӷ�����Ϊ[x, i],  x-1��ζ��x�������1, ������õ��ӷ���������һ���˷�һ���ӷ� 
			for(int x = 2; x <= i; x++)
			{
				dp[i][j] = max(dp[i][j], dp[x - 1][j - 1] * (sum[i] - sum[x - 1]));
			} 
		}
	}
	
	cout << dp[n][k];
	
	return 0;
} 
