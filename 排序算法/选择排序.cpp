#include<stdio.h>

	
void SelectSort(int *a,int n)//从小到大排序
{
	int i,j,k,temp;



	for( i = 0; i < n; i++)//从a[0]到a[n-1]的区间进行排序
	{
		k = i;//不能少，因为如果a[k]跟a[i]同位置，k将会在已排好的部分里，而之后i++便会跟已排好的交换，，，
		for( j = i; j < n; j++ )//从[i,n]中选出最小的放到最前面(这里把下标标为k)
		{
			if( a[j] < a[k] )
				k = j;
		}
	
		temp = a[i];
		a[i] = a[k];
		a[k] = temp;

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

	SelectSort(a,n);


	for( i = 0; i < n; i++)
		printf("%d	",a[i]);

	getchar();
	getchar();
	return 0;
}