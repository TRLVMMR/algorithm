#include<cstdio>
#include<math.h>

long long gcd(long long a, long long  b)
{
	return !b ? a : gcd(b, a % b);
}

int main()
{
	long long n;
	long long endb = 1;
	
	long long enda = 0;	
	
	scanf("%lld", &n);
	
	while(n--)
	{
		long long a,b;
		long long temp = endb;
		
		scanf("%lld/%lld", &a, &b);
		
		//最小公倍数给endb 
		endb = endb / gcd(b, endb) * b;
		//分子调整 
		enda = a * (endb / b) + enda * (endb / temp);
		
	}
	
	
	long long temp = gcd(enda, endb);
	
	enda = enda / temp;
	endb = endb / temp;
	
	if(endb < 0)
	{
		endb = -endb;
		enda = -enda;
	}
	
	long long intger = 0;
	
  int flag = 0;
	
	if(abs(enda) > abs(endb))
	{
		intger = enda / endb;
		enda = enda % endb;
	}
	
	if(intger != 0)
	{
		printf("%lld", intger);
		
		if(enda == 0)
		{
			flag = 1;
		}
		else
		{
		  printf(" ");
		}
	}
	
  if(flag == 0)
  {
  	if(intger == 0 && enda == 0)
  	{
  		printf("0\n");
  	}
  	else
  		printf("%lld/%lld\n", enda, endb);
  }
  else if(flag == 1)
  {
    printf("\n");
  }

	return 0;
}
