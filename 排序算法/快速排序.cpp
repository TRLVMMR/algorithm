#include<stdio.h>

int a[256];

void quicksort(int left,int right)
{
	int temp,i,j,k;

	if (left > right)
		return;

	temp = a[left];//取最左边的数为基准数
	//初始化i，j的位置再最左跟最右位置
	i = left;
	j = right;

	while( i != j )//快速排序核心：如果i跟j不同位，进行排序，如果同位置，此位即基准数的位置
	{
		//必须从右边先开始，因为左边提供了一个基准位来比较了，如果还从左边开始，每次基准位都会偏右
		//因为先开始的一方，会占领比他小（或大）的位置。 因此，如果从左边开始，每次都会把比它大的数扔到最左边，这是不合理的 
		while( i < j && a[j] >= temp )
			j--;
		while( i < j && a[i] <= temp )
			i++;//由于i!=j，且i<j,i跟j都是整数，所以，结果i一定小于j，不用担心i>j的情况，
				//但结果可能i=j，此时跳出排序，进行交换即可

		//交换大小两个数的位置，让大的数在右边，小的在左边
	if( i < j )
	{
		k = a[i];
		a[i] = a[j];
		a[j] = k;
	
	}
	}


	//排序结束，让基准数归位，交换最后个位置与基准数
	a[left] = a[i];
	a[i] = temp;

	quicksort( left, i-1 );
	quicksort( i+1, right );

	return;
}


int main()
{
	int i,n;
	
	printf("请输入要排序的个数");
	scanf("%d",&n);

	printf("请输入%d个排序的数",n);

	for(i = 1; i <= n; i++)
		scanf("%d",&a[i]);

	quicksort(1,n);

	for(i = 1; i <= n; i++)
		printf("%d	",a[i]);

	getchar();
	getchar();
	return 0;
}
