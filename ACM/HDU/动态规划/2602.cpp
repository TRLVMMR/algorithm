/*
		�������Ϊ0��״̬�� v����0ö�ٻ������ 
		
		
*/
#include<stdio.h>
#include<algorithm>

using namespace std;

int dp[1000][1000];

int main()
{
	freopen("2602.txt", "r", stdin);
	int t;
	
	scanf("%d", &t);
	
	while(t--)
	{
		int n, vol;
		int p[1000] = {0}, w[1000] = {0};
		
		scanf("%d %d", &n, &vol);
		
		for(int i = 1; i <= n; i++)
			scanf("%d", &p[i]);
		for(int i = 1; i <= n; i++)
			scanf("%d", &w[i]);	

		//�߽� 	
		for(int v = 0; v <= vol; v++)
			dp[0][v] = 0;
	//	memset(dp, 0, sizeof(dp));//û��Ҫ����Ϊһ�δθ����� 
		
		for(int i = 1; i <= n; i++)
		{
			for(int v = 0; v <= vol; v++)
			{
				if(v >= w[i])
					dp[i][v] = max(dp[i-1][v], dp[i-1][v-w[i]] + p[i]);
				else
					dp[i][v] = dp[i-1][v];
			}
		}
		
		
		printf("%d\n",dp[n][vol]);
		
	
	} 
	
	return 0;
}
