/*
	������n����n������ÿ�������������ӣ�������������ͬһ������
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

	printf("������������");
	scanf("%d",&n);

	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= i; j++)
			scanf("%d",&f[i][j]);

		//�߽磺���һ����dp����ֵ������������
	for(i = 1; i <= n; i++)
		dp[n][i] = f[n][i];

	for(i = n-1; i >= 1; i--)//�ӵ����ڶ��㿪ʼ
	{
		for(int j = 1; j <= i; j++)
			dp[i][j] = max(dp[i+1][j],dp[i+1][j+1]) + f[i][j];//����һ�����߻����ұ�����һ���Ӽ��ϴ˵��Ȩֵ����¼Ϊ�˵����Ȩֵ
		//״̬ת�Ʒ��̣�dp[i][j] = max{dp[i+1][j],dp[i+1][j+1]}+f[i][j]
	}
	
	printf("%d\n",dp[1][1]);

	return 0;
}