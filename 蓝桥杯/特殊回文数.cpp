/*
	输入一个正整数n， 编程求所有这样的五位和六位十进制数，满足各位数字之和等于n 。
	
	首先知道一个规律，回文数，即左右一样，因此：若n为奇数，则一定为5位数 
*/
#include<stdio.h>

int main()
{
	int n;
	
	scanf("%d", &n);
	 
	if(n % 2 == 0)
	{
		//6位数的情况 
		int m = n / 6;
		int temp = n - 6 * m;//表示有几个m 
		
		//5位数的情况(n <= 45) 
	}
	//5位数 
	else
	{
	
	} 
	
	return 0;
} 
