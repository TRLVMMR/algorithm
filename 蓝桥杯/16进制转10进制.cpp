#include<stdio.h>
#include<string.h>

int main()
{
	char h[10];
	
	scanf("%s", h);
	
	int len = strlen(h);
	long long sum = 0;
	
	for(int i = 0; i < len; i++)
	{
		if(h[i] >= '0' && h[i] <= '9')
		{
			sum = sum * 16 + h[i] - '0';
		}	
		else if(h[i] >= 'A' && h[i] <= 'F')
		{
			sum = sum * 16 + h[i] - 'A' + 10;
		}
	}
	
	printf("%lld\n", sum);
	
	return 0;
} 
