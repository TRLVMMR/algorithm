#include<stdio.h>

int main()
{
	long long n;
	long long sum;
	
	scanf("%lld",&n);
	
	if(n % 2 == 0)
	{
		sum = n / 2 * (n + 1);
	} 
	else
	{
		sum = (n + 1) / 2 * n; 
	}
	
	printf("%lld", sum);
	
	return 0;
} 
