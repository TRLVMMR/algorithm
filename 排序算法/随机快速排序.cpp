/*
	快速排序在元素比较随机化时效率最高，越有序越接近O(n^2)
	快速排序的期望时间复杂度是O(nlogn),最差为O(n^2)，特定数据会产生最差的结果，所以选择随机化
	随机快速排序对任意数据的期望时间复杂度都是O(nlogn),但最差还是O(n^2)

*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>


void swap(int *i,int *j)
{
	int k;

	k = *i;
	*i = *j;
	*j = k;

}


void quickSort(int *a,int left,int right)
{
	int i,j;
	int p;

	if( right < left )
		return;
	//生成随机数p
	srand( (unsigned)time(NULL) );
	p = (int)(0.5 + (1.0 * rand() / RAND_MAX * (right - left) + left));

	swap( &a[left], &a[p] );


	i = left;
	j = right;

	while(i != j)
	{
		while( j > i && a[j] >= a[left] )
				j--;
		while( j > i && a[i] <= a[left] )
				i++;
		if( j > i )
			swap(&a[i],&a[j]);
	}

	swap(&a[left],&a[i]);

	quickSort(a, left, i-1);
	quickSort(a, i+1, right);
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

	quickSort(a, 0, n-1);


	for(i = 0; i < n; i++)
		printf("%d	",a[i]);

	getchar();
	getchar();
	return 0;
}