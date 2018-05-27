#include<stdio.h>
#include<algorithm>

using namespace std;

int a[20];

int main()
{
	int n;
	
	scanf("%d", &n);
	
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	
	sort(a, a+n);
	
	for(int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	
	return 0;
} 
