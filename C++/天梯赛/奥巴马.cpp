#include<cstdio>

int main()
{
	int n;
	char c;
	
	scanf("%d %c", &n, &c);
	
	for(int i = 0; i < (n+1)/2; i++)
	{
		for(int j = 0; j < n; j++)
			printf("%c", c);
		
		printf("\n");
	}
	
	
	
	return 0;
}
