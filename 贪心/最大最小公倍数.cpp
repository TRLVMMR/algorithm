#include<iostream>

using namespace std;

long long gcd(long long a, long long b)
{
	return (b == 0) ? a : gcd(b, a % b); 
	
 } 
 
 long long min_s(long long  a, long long b)
 {
 	long long g = gcd(a, b);
 	
 	return a / g * b; 
 }

long long max_mins(int n)
{
	if(n == 1)
		return 1;
	else if(n == 2)
		return 2;

	//相邻两个数一定互质 
	long long sum = n * (n - 1);
	//贪心，尽量选择大的互质的数 
		
	for(int k = n - 2; k >= 1; k--)
	{
		if(gcd(sum, k) == 1)
		{
			return sum * k;
		}	
	}
}

int main()
{
	int n, sum;
	
	cin >> n;
	
	cout << max_mins(n);
	
	return 0;
 } 
