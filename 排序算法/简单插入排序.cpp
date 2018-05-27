/*
	[1,i-1]为排序好部分，[i,n]为待排序部分

*/
#include<stdio.h>

void InsertSort(int *a,int n)//从小到大
{
	int i,j,temp;

	for( i = 1; i < n; i++ )//默认第一个数排序好，从第二个数开始排序,进行n-1次排序
	{
		temp = a[i];
		j = i;

		while( j > 0  &&  temp < a[j-1] )//大的数进行让位，让到属于temp的位
									//如果在最前面即a[0]位置，j会等于0,然后判断j>0不成立，跳出循环
		{
			a[j] = a[j-1];//比temp大的向后移
			j--;
		}
		
		a[j] = temp;//找到temp该有的位置插入
	
	}


}

int main()
{
	int a[256];
	int i = 0,n = -1;

	printf("请输入需要排序的数，按p结束");

	do
	{	
		
		scanf("%d",&a[i]);
		i++;
		n++;
	}while('p' != getchar());

	InsertSort(a,n);


	for( i = 0; i < n; i++ )
		printf("%d	",a[i]);

	getchar();
	getchar();
	return 0;
}