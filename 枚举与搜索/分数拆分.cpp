/*
	����һ��������n���������1/n = 1/x + 1/y (����x >= y)
*/
#include<stdio.h>

int mult(int x,int y)
{
	int a = x,b = y, c; 
	//շת����������Լ��
	while(b != 0)//��������Ϊ0Ϊֹ
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
	printf("������һ������������������з������\n");
	scanf("%d",&n);

	for(i = n+1; i <= 2*n; i++)
	{
			mul = mult(i,n);//�ҵ�i��n����С������

			if(mul % (mul/n - mul/i) == 0)//�����ĸ���ӿɻ���,��������Ϊ1�����
			{	
				mul = mul / (mul/n - mul/i);
				printf("1/%d = 1/%d + 1/%d\n",n,mul,i);
			}

	}

}