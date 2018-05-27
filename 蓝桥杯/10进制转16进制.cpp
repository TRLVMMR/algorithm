#include<stdio.h>
#include<string.h>

char h[100], t[100];

int main()
{
	int a;

	scanf("%d", &a);
	
	int len = 0;
	
	if(a == 0)
	{
		printf("0\n");
		return 0;
	}
	while(a != 0)
	{
		int temp = a % 16;
		if(temp < 10)
		{
			t[len++] = temp + '0';
		}
		else
		{
			t[len++] = temp - 10 + 'A';
		}
		a /=  16;
	}
	
	//µ¹×Å¸³Öµ 
	for(int i = 0; i < len; i++)
	{
		h[i] = t[len - 1 - i];
	}
	
	printf("%s", h);
	
	
	return 0;
} 
