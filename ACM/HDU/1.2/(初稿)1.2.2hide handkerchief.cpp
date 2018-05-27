#include<stdio.h>
#define MAXV  100000000 
bool flag[MAXV+1];

int main()
{
	int n, m, first = 1;//ÆðµãfirstÎª1 
	
	flag[1] = 1;
	while (scanf("%d %d",&n,&m) != EOF)
	{
		if(n == -1 && m == -1)
			break;
		memset(flag,0,sizeof(flag));
		for(int i = 1; i <= n; i++)
		{
			first = first + m;
			if(first > n)
			{
				first = first % n;
			}
		
			flag[first] = 1;
		}
		int ok = 1;
		for(int i = 1; i <= n; i++)
		{
			if(!flag[i])
			{
				ok = 0;
				break;
			}	
		}
		if(ok)
		{
			printf("YES\n");
		}
		else
		{
			printf("POOR Haha\n");
		}
	}
	
	
	return 0;
}
