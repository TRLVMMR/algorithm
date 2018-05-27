/*
	实质上是判断互质 
*/
#include<stdio.h>

int gcd(int a,int b)
{
	return b == 0 ? a : gcd(b, a%b);
}

int main()
{
	int n, m;
	while (scanf("%d %d",&n,&m) != EOF)
	{
		if(n == -1 && m == -1)
			break;
		int g = gcd(n, m);
		if(g == 1)
			printf("YES\n");
		else
			printf("POOR Haha\n");
	}
	return 0;
}
