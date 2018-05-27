#include<stdio.h>

int main()
{
	int n;
	
	for(int i = 100; i < 1000; i++)
	{
		int temp1 = i % 10;
		int temp2 = (i / 10) % 10;
		int temp3 = (i / 100) % 10;
		if(i == temp1 * temp1 * temp1 + temp2 * temp2 * temp2 + temp3 * temp3 * temp3)
		{
			printf("%d\n", i);
		}
		
	}
	
	
	return 0;
} 
