#include<cstdio>
#include<algorithm>

using namespace std;

const int maxn = 100;//物品最大件数
const int maxv = 1000;//V的上限
int w[maxn],c[maxn],dp[maxn];

int max(int a,int b)
{
	return a > b ? a : b;
}

int main()
{
	int n,V;
	scanf("%d%d",&n,&V);
	for(int i = 0; i < n; i++)
		scanf("%d",&w[i]);
	for(i = 0; i < n; i++)
		scanf("%d",&c[i]);

	//边界
	for(int v = 0; v <= V; v++)
		dp[v] = 0;

	for(i = 1; i <= n; i++)
	{
		for( v = V; v >= w[i]; v--)
			dp[v] = max(dp[v],dp[v-w[i] ]+ c[i]);

	
	}

	int max = 0;
	for(v = 0;v <= V; v++)
	{
		if(dp[v] > max)
			max = dp[v];
	
	}
	
	printf("%d\n",max);
	return 0;
}