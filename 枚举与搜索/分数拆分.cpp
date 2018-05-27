/*
	输入一个正整数n，输出所有1/n = 1/x + 1/y (其中x >= y)
*/
#include<stdio.h>

int mult(int x,int y)
{
	int a = x,b = y, c; 
	//辗转相除法求最大公约数
	while(b != 0)//除到余数为0为止
	{
		c = a % b;
		a = b;
		b = c;
	}

	return x * y / a;

}

int main()
{
	int n,i,mul;
	printf("请输入一个数，将输出它的所有分数结果\n");
	scanf("%d",&n);

	for(i = n+1; i <= 2*n; i++)
	{
			mul = mult(i,n);//找到i跟n的最小公倍数

			if(mul % (mul/n - mul/i) == 0)//如果分母分子可化简,包括分子为1的情况
			{	
				mul = mul / (mul/n - mul/i);
				printf("1/%d = 1/%d + 1/%d\n",n,mul,i);
			}

	}

}