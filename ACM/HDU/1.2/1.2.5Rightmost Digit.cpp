/*
	���n^n�ĸ�λ�� 1<= n <= 1,000,000,000 
	˼·1��ֻ����λ
,	˼·��������ʵ0��1��6ÿ��һ��(һ��һȦ)��9,5,4Ҫ3�η�(��ÿ2��һȦ����),2��3��7��8Ҫ5�η���ÿ4��һȦ����
*/


/*	csdn��һ��˼·����λ��������ڲ����10
	����
	bool l[10];//������¼һ����������Щ�� 
	int r[10];//��¼һ�����ڵ�����ʲô˳�� 
	//�����ں���,���bû�г��ֹ�������ѭ�� 
	 while(!l[b])
       {
               l[b]=true;
                r[i++]=b;
                b=(b*a)%10;//aΪsum�ĸ�λ�� 
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
		//�ҵ�sum�ĸ�λ 
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
				if(!j)//�������Ϊ0���ǿ϶���4�ı��� 
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
		//sum��sum�η��ĸ�λ 
			i = i % 10;
		printf("%d\n",i);
		
	} 
	
	
}
