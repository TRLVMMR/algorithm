/*
	��HAL����IBM����ÿ����ĸ���ɺ�һ����ĸ 

*/

#include<stdio.h>
#include<string.h>

int main()
{
	int n;
	
	scanf("%d",&n);
	
	for(int i = 1; i <= n; i++)
	{
		char a[100];
		scanf("%s",a);
		
		int alen = strlen(a);
		for(int j = 0; j < alen; j++)
		{
			if(a[j] == 'Z')
				a[j] = 'A';
			else
				a[j]++;
			
		}
		printf("String #%d\n",i);
		printf("%s\n\n",a);
		
		
	}
	
	
	return 0; 
} 
