#include<stdio.h>

int main()
{
	
	for(int i = 1000; i <= 9999; i++)
	{
		int temp1 = i / 100;
		int temp2 = (i % 100) / 10 + ((i % 100) % 10) * 10;//将后两位数颠倒顺序 
		
		if(temp1 == temp2)
		{
			printf("%d\n", i);
		} 
		
		
	}
	
	return 0;
} 
