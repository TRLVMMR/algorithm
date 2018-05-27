/*
	输出n^n的个位数 1<= n <= 1,000,000,000 
	思路1：只看个位
,	思路：基于事实0，1，6每次一样(一次一圈)，9,5,4要3次方(即每2次一圈走完),2，3，7，8要5次方（每4次一圈），
*/


/*	csdn上一个思路：个位数相乘周期不会过10
	所以
	bool l[10];//用来记录一个周期有哪些数 
	int r[10];//记录一个周期的数是什么顺序 
	//找周期函数,如果b没有出现过，进入循环 
	 while(!l[b])
       {
               l[b]=true;
                r[i++]=b;
                b=(b*a)%10;//a为sum的个位数 
       } 
*/

#include<stdio.h>
#include<math.h>

int main()
{
	int n;
	
	scanf("%d", &n);
	while(n--)
	{
		int i, sum;
		scanf("%d",&sum);
		i = sum;
		//找到sum的个位 
			i = i % 10;
		switch(i)
		{
			case 0: case 1: case 6:
			{
				
				break;			
			}
			case 2: case 3: case 7: case 8:
			{
				int j = sum % 4;
				if(!j)//如果余数为0，那肯定是4的倍数 
					i = pow(i, 4);
				else
					i = pow(i, j);	
				break;
			}
			case 4: case 5: case 9:
			{
				int j = sum % 2;
				if(!j) 
					i = pow(i, 2);
				else
					i = pow(i, j);
				break;
			}
		}
		//sum的sum次方的个位 
			i = i % 10;
		printf("%d\n",i);
		
	} 
	
	
}
