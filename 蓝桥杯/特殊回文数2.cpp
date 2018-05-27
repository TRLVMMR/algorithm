/*

	一开始用fj来记录j的反序，但是出现问题，当j = 50时，fj是5而不是05 

*/
#include<stdio.h>

//5位数的情况 (奇数时传入k为1，偶数传入0)
void  five(int n, int k)
{
	if(n > 45)
		return;
	
	//i为最中间的数 

		
		//j为两边的数 
	for(int j = 10; j < 100; j++)
	{
		int temp = j, sum = 0;
		
		for(int i = k; i <= 9; i+=2)
		{
			
			int m = (n - i) / 2; 
			while(temp != 0)
			{
				sum = sum + temp % 10;
				temp /= 10;
			}
			if(sum == m)
			{
				temp = j;
				temp = temp * 10 + i;
				temp = temp * 10 + j % 10;
				temp = temp * 10 + (j / 10) % 10;
				
				printf("%d\n", temp);
				
			}
		}
	} 
	
}



int main()
{
	int n;
	
	scanf("%d", &n);
	
	if(n % 2 == 0)
	{
		five(n, 0);
		int m = n / 2;
		//6位数的情况(由于后三位一样，只需前三位判断)
		for(int i = 100; i < 1000; i++)
		{
			int temp = i, sum = 0;
			while(temp != 0)
			{
				sum = sum + temp % 10;
				temp /= 10;
			}
			if(sum == m)
			{
				temp = i;
				sum = i;
				while(temp != 0)
				{
					sum = sum * 10 + temp % 10; 
					temp /= 10;
				}
				
				printf("%d\n", sum);
			
			}
			
		}
	
	}
	else
	{
		five(n, 1);
	}
	
	
	return 0;
} 
