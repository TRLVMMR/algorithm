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

	printf("������n����ֵ");
	scanf("%d",&n);
	for(int i = 1; i <= n; i++)
		scanf("%d",&A[i]);

	
	
	for(i =1; i <= n; i++)
	{	
		dp[i] = 1;//��ʼ������������ÿ��Ԫ���Գ�������
		for(int j = 1; j < i; j++)//����iǰ������Ԫ�أ�����iǰ��Ԫ�ر�iС���ҳ���
		{
			if(A[i] >= A[j] && dp[j] +1 > dp[i])//��ǰ���Ԫ�������dp+1��dp[i]
												//��¼ÿ�ε������Ϊֹ����ȣ�����и����Ͱѳ��ĸ�dp[i]
			{
				dp[i] = dp[j] + 1;
			}
		}
		ans = max(ans,dp[i]);//ÿ�μ�¼��ģ�������ӵ�Ŀ���ǵ��²�����ȥ����һ��
	}

	printf("%d\n",ans);

	return 0;
}