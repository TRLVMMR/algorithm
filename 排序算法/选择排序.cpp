#include<stdio.h>

	
void SelectSort(int *a,int n)//��С��������
{
	int i,j,k,temp;



	for( i = 0; i < n; i++)//��a[0]��a[n-1]�������������
	{
		k = i;//�����٣���Ϊ���a[k]��a[i]ͬλ�ã�k���������źõĲ������֮��i++�������źõĽ���������
		for( j = i; j < n; j++ )//��[i,n]��ѡ����С�ķŵ���ǰ��(������±��Ϊk)
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

	printf("��������Ҫ�����������p����");

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