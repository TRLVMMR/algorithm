#include<cstdio>
#include<cstring>
#include<iostream>
#include<string>
#include<queue>
#include<stack>
#include<map>
#include<algorithm>
#include<set>
#include<vector>

using namespace std;

struct Bignum
{
	char num[45000];
	int len;	
};

Bignum sum;

void Bignum_mult(int b)
{
	int carry;
	
	for(int i = 0; i < sum.len; i++)
	{
		carry = sum.num[i] * b + carry;	
		sum.num[i] = carry % 10;
		carry /= 10;
		
	}
	
	while(carry != 0)
	{
		sum.num[sum.len++] = carry % 10;
		carry /= 10;
	}
	
	
}


int main()
{
	int n;
	
	cin >> n;
	
	sum.num[0] = 1;
	sum.len = 1;
	
	for(int i = 1; i <= n; i++)
	{
		Bignum_mult(i);
		
	}
	
	for(int i = sum.len - 1; i >= 0; i--)
	{
		printf("%d", sum.num[i]);
	}
	cout << endl;
	
	return 0;
}
