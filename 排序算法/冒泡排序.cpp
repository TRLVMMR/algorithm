#include<stdio.h>

int main()
{
	int a[256];
	int i,j,n,temp;

	printf("请输入要排序的个数");
	scanf("%d",&n);

	printf("请输入%d个数",n);
	for( i = 0; i < n; i++ ) 
		scanf("%d",&a[i]);
	
	//冒泡排序
	for( i = 1; i <= n-1; i++ )//进行n-1次比较，i++都代表一个数完成排序
		//i必须为1，不能为0，否则a[j]会等于a[n],而存储的只到a[n-1]
		for( j = 0; j < n-i; j++)
			if(a[j] > a[j+1])
			{
				temp = a[j];
				a[j] = a[j+1];
				a[j+1] = temp;
			}

	for( i = 0; i < n; i++ )	
		printf("%d",a[i]);

	getchar();
	getchar();
	return 0;
}