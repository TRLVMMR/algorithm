#include<stdio.h>

int main()
{
	int a[256];
	int i,j,n,temp;

	printf("������Ҫ����ĸ���");
	scanf("%d",&n);

	printf("������%d����",n);
	for( i = 0; i < n; i++ ) 
		scanf("%d",&a[i]);
	
	//ð������
	for( i = 1; i <= n-1; i++ )//����n-1�αȽϣ�i++������һ�����������
		//i����Ϊ1������Ϊ0������a[j]�����a[n],���洢��ֻ��a[n-1]
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