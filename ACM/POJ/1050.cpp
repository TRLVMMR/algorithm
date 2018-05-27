#include<stdio.h>
#include<algorithm>
#define MAXV 100

using namespace std;

int num[100][100];
int dp[100][100];

int main()
{
	int n;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{	
			scanf("%d",&num[i][j]);	
			
			//先计算每行的最大子段和 
			if(j == 0)
				dp[i][j] = num[i][j];
			else
				dp[i][j] = max(num[i][j],dp[i][j-1] + num[i][j]);
		}
	}
	
	

	
	
	
	return 0;
} 
