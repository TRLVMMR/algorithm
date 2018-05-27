/*
	有盖圆柱容器表面积为1000，输入容积，求最小半径，保留一位小数 

	表面积为：S = 2π*（r*r + r*l） 需满足2πr*r < 1000 
	容积为：v = π*r*r*l 

	消l整理得：v = S / 2 * r - π*r*r 
	从小到大枚举r，得到的解肯定是最优解 
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
		 	
		 	//用1000表面积组成容器的体积大于v就行 
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
