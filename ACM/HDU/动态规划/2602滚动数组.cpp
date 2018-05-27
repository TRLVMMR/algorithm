#include<stdio.h>
#include<cstring>
#include<algorithm>

using namespace std;

int dp[1000];

int main()
{
//	freopen("2602.txt", "r", stdin);
	int t;
	
	scanf("%d", &t);
	
	while(t--)
	{
		int n, vol;
		int p[1000], w[1000];
		
		scanf("%d %d", &n, &vol);
		
		
		for(int i = 1; i <= n; i++)
			scanf("%d", &p[i]);
		for(int i = 1; i <= n; i++)
			scanf("%d", &w[i]);	

		//±ß½ç 	
		memset(dp, 0, sizeof(dp));
		
		
		for(int i = 1; i <= n; i++)
		{
			for(int v = vol; v >= w[i]; v--)
				dp[v] = max(dp[v], dp[v - w[i]] + p[i]);

		}
		
		
		printf("%d\n",dp[vol]);
		
		
	} 
	
	return 0;
}
