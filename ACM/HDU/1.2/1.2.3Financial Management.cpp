#include<stdio.h>

int main()
{

	double add,sum = 0;
	
	for(int i = 0; i < 12; i++)
	{
		scanf("%lf",&add);
		sum = sum + add;
	}
	
	printf("$%.2f\n",sum/12);
}
