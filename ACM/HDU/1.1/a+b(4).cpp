#include<stdio.h>

int main()
{
	int n, a;
	
	while(scanf("%d",&n) != EOF)
	{
		int sum = 0;
		if(n == 0)
			break;
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&a);
			sum = sum + a;
		}
		
		printf("%d\n",sum);
	}
	
	return 0;
}
