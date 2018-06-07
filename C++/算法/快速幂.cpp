/*
	计算a^b % m的值:
	 
	*1.一个数的取余
	 
		a^b % m的值等于 (a^n % m * a^(b-n)) % m 	(n < b)的值
		 
	*2.快速幂：
	
		@方法：a为奇数时才累计 
				 	
			原因：
			*	  b为奇数：a^b = a^(b-1) * a
			*	  b为偶数: a^b = a^(b/2) * a^(b/2)
			*	所以一个数就可以不断拆分到幂为0为止
				 
			*	一个数也可以用二进制表示，然后拆分 
			*	b不断变小，但即使b也有成为奇数的时候，即2^0 = 1	  
			*	实质是不断分治,快速幂则是把每个需要的值一次性算出来 
			 
	 
*/
#include<cstdio>
#define LL long long 

/* 
	快速幂原理，不断分治， 
*/
int quick_pow(LL base, LL pow, const int m)
{
	
	int ans = 1;
	
	while(pow > 0)
	{
		//如果pow是奇数 
		if(pow & 1)
		{
			ans = ans * base % m; 
			
		}
		base = base * base % m;
		
		pow >>= 1; // b右移一位 
		
	}
	
}


int main()
{
	
	
	return 0;
}
