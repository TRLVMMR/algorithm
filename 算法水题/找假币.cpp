/*
	问题： 
	有n个硬币，其中有一个假币，请问最少几次能保证找到假币 
		三分硬币；
			当n % 3 == 0 : 分为n/3, n/3, n/3 
			当n % 3 == 1: 分为n/3, n/3, (n/3) + 1
			当n % 3 == 2： 分为n/3, (n/3)+1, (n/3) +1 
		
		由于涉及涉及除法循环关于k^n，应考虑迭代最后n = 1时的情况， 即3^n 会比非3^n特殊
		 
		下面的几种方法都没有解决“一开始”n=0跟n=1的问题，因为，没有意义，此时不需要分 
*/
#include<iostream>
#include<cmath>

using namespace std;

int end1(int n)
{
	int ans = 0;
	
	//如果n为3^n，比如n=9，就会有9/3 = 3, 3/3 = 1，使用n--错开一位数，让n/3 < 1，C语言把它变成0， 
	//好处：3^n跟普通3的倍数都可以被正确处理,因为 
	if(n % 3 == 0)
		n--;
	
	while(n > 0)
	{
		n /= 3;
		ans++;
	}
	
	return ans;
}

//这个函数是错误的 
int end2(int n)
{
	int ans = 0;
	
	//不行，相当于n-1 > 0，对n % 3 == 1是灾难，因为它变得跟原问题的n % 3 == 0一样特殊 
	while(n > 1)
	{
		n /= 3;
		ans++;
	}
	
	return ans;
}

int end3(int n)
{
	int ans = 0;
	
	//处理了3^n, 也可行，但速度慢 
	if(n % 3 == 0)
		for(int i = 0; i < 100; i++)
		{
			int mark = pow(3, i);
			if(n < mark)  break;
			else if ( n == mark) ans--;
		}
		
	
	while(n > 0)
	{
		n /= 3;
		ans++;	
	}	
	
	return ans;
} 

int end4(int n)
{
	int ans = 0;
	 
	double temp = log(n) / log(3);
	/*
	 * 如果log结果是整数, 证明是3^n, 次数减1 
		if(int(temp) == temp) ans--;

	  小数下溢，所以加1 
		ans += int(temp) + 1;
		与下面方法相同 
	*/
	
	//如果log结果不是整数，则由于小数 
	if(temp > int(temp))
		ans++;
	ans += int(temp);
	
	return ans;	
} 

int main()
{
	int n;
	
	cin >> n;
	for(int i = 2; i < n; i++)
	{
		if(end1(i) != end4(i))
		{
			cout << i << endl;
			cout << end1(i) << " != " << end4(i) << endl;  
		}
		
	}
	
	return 0;
} 
