/*
	思路：十六进制转二进制再转八进制 
 
*/
#include<stdio.h>
#include<string.h>

char h[100001];
char b[500000];
char o[200020];

//十六进制转十进制z再转二进制 
void htob()
{
	memset(b,0 ,sizeof(b));
	int len = strlen(h);
	//把十六进制的字符转成对应的10进账数 
	for(int i = 0; i < len; i++)
	{
		int sum;
		if(h[i] >= '0' && h[i] <= '9')
		{
			sum = h[i] - '0';
		}	
		else if(h[i] >= 'A' && h[i] <= 'F')
		{
			sum = h[i] - 'A' + 10;
		}
		
		//十进制转二进制 ,十六进制1个位对应二进制4个位  
		for(int j = 1; j <= 4; j++)
		{
			//位数不够补0 
			if(sum == 0)
			{
				b[(i+1) * 4 - j] = '0';
			}
			else
			{
				b[(i+1) * 4 - j] = sum % 2 + '0';
				sum /= 2;
			}

		}
			
	}
	
}

//二进制转八进制 
void btoo()
{
	memset(o, 0,sizeof(o));
	int len = strlen(b);
	//位数可能不是3的倍数，所以要做处理(这里取前一两位当成三位处理) 
	int temp = len % 3; 
	int sum = 0;
	
	if(temp == 0) 
		temp = 3;
		
	for(int i = 0; i < temp; i++)
		sum  = sum * 2 + b[i] - '0';
	o[0] = sum + '0';


	int k = 1;//由于八进制的0位已经放了，从1位开始 
	for(int i = temp; i < len; i+=3)
	{
		sum = 0;
		//j是偏移量 
		for(int j = 0; j < 3; j++)
		{
			sum = sum * 2 + b[i + j] - '0';
		}
		
		o[k] = sum + '0';
		k++;
	}
	

	
}

int main()
{
	int n;
	
	scanf("%d", &n);
	
	for(int j = 0; j < n; j++)
	{
		memset(h, 0, sizeof(h));
		scanf("%s", h);	
		
		htob();	//16转2 
		btoo();//2转8 
		
		//找到第一个不为0的的位开始输出 
		int olen = strlen(o);
		int ok = 1;
		for(int i = 0; i < olen; i++)
		{
			if(o[i] != '0')
			{
				printf("%s\n", &o[i]);
				ok = 0;
				break;
			}
		}
		//如果所有位都为0，则输出0 
		if(ok)
		{
			printf("0\n");
		}
		
	}
	
	
	return 0;
} 
