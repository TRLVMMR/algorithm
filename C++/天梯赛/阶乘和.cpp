#include<cstdio>

int main()
{
	int n;
	long long ans = 0;
	
	scanf("%d", &n);
	
	
	for(int i = 1; i <= n; i++)
	{
		int temp = 1;
		for(int j = 1; j <= i; j++)
		{
			temp = j * temp;
		}
		ans = temp + ans;
	}
	
	printf("%d\n", ans);
	
	
	return 0;
}
