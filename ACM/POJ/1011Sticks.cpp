/*
	把若干根一样长度的木棒切成n段，
	题目：已知n段跟每段长度，求原来最小的长度 
*/
#include<stdio.h>
#include<algorithm>

using namespace std;

bool cmp(int a, int b)
{
	return a > b;
}

int main()
{
	int n;
	
	while(scanf("%d", n) && n != 0)
	{
		int len[100] = {0};
		
		for(int i = 0; i < n; i++)
		{
			scanf("%d",&len[i]);
		}
		
		sort(len, len+n, cmp);
		

	}
	
	
	return 0;
}
