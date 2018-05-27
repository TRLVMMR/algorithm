#include<stdio.h>

//将A数组的，[L1，R1],[L2，R2]区间排序并合并
void merge(int A[],int L1,int R1,int L2,int R2)
{
	int i = L1,j = L2;
	int temp[256],index = 0;//temp用来临时存放，index是temp的下标

	while(i <= R1  &&  j <= R2)//排序部分
	{
		//每次把两个组最小的进行比较，然后把较小的放到temp中
		if( A[i] <= A[j] )
			temp[index++] = A[i++];
		if( A[j] <= A[i] )
			temp[index++] = A[j++];

	
	}

	//如果其中一个数组的数用完，则把另一个数组剩余的数加入temp
	while( i <= R1 )
		temp[index++] = A[i++];
	while( j <= R2 )
		temp[index++] = A[j++];

	//将temp数组放回去A数组
	for(i = 0; i < index; i++)
		A[L1 + i] = temp[i];


}

//递归实现归并排序
void mergeSort(int A[],int left,int right)//left是最左边的下标
{
	if(left < right)
	{
		//取[left,right]的中点进行划分(可取其他点)
		int mid = (left + right) / 2;
		
		mergeSort(A, left, mid);
		mergeSort(A, mid+1, right);
	
		merge(A, left, mid, mid+1, right);//将左右子区间合并并排序
	}
	//返回时是两个只有一张，排序合并后变成两张，再返回有又两个排序好的两张，递归到最后每次都是排序好的
}

//非递归实现归并排序

int main()
{
	int A[256];
	int i,n;

	printf("请输入要排序的个数");
	scanf("%d",&n);

	printf("请输入%d个数",n);
	for( i = 0; i < n; i++ )
		scanf("%d",&A[i]);
	
	mergeSort(A, 0, n-1);

	for( i = 0; i < n; i++ )
		printf("%d	",A[i]);

	getchar();
	getchar();
	return 0;
}