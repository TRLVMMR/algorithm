#include<stdio.h>
#include<string.h>

int main()
{
	int l, r;
	
	while(scanf("%d %d", &l, &r))
	{
		int sum = 0;
		
		if(r == 0 && l == 0)
			break;
			
		for(; l <= r; l++)
		{
			int ok = 0;

			//Ѱ��l�ĸ�λ�������Ƿ�4 
			for(int temp = l; temp != 0; temp /= 10)
			{
				if(temp % 10 == 4)
				{
					ok = 1;
					break;
				}	
			}
			
			if(ok)
				continue;
			
			sum++;
		}
		
		printf("%d\n", sum);
	}
	
	return 0;
}
