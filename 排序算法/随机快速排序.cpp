/*
	����������Ԫ�رȽ������ʱЧ����ߣ�Խ����Խ�ӽ�O(n^2)
	�������������ʱ�临�Ӷ���O(nlogn),���ΪO(n^2)���ض����ݻ�������Ľ��������ѡ�������
	�������������������ݵ�����ʱ�临�Ӷȶ���O(nlogn),������O(n^2)

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
	//���������p
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

	printf("��������Ҫ�����������p����");

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