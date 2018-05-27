/*
	�и�Բ�����������Ϊ1000�������ݻ�������С�뾶������һλС�� 

	�����Ϊ��S = 2��*��r*r + r*l�� ������2��r*r < 1000 
	�ݻ�Ϊ��v = ��*r*r*l 

	��l����ã�v = S / 2 * r - ��*r*r 
	��С����ö��r���õ��Ľ�϶������Ž� 
*/
#include<stdio.h>
#include<math.h>
#define PAI 3.14159

int main()
{
	int t;
	
	scanf("%d", &t);
	
	while(t--)
	{
		int v;
		scanf("%d", &v);
		
		int ok = 1; 
		 
		for(double r = 0.01; PAI * r * r  <= 500; r += 0.01)
		{
			
		 	double guess = 500 * r - PAI * r * r * r;
		 	
		 	//��1000���������������������v���� 
			if(guess >= v)
			{	
				printf("%.1lf\n", r);
				ok = 0;
				break;
			}
		}
		
		if(ok)
		{
			printf("NO\n");
		}
		
	}
	
	return 0;
} 
