/*
	[1,i-1]Ϊ����ò��֣�[i,n]Ϊ�����򲿷�

*/
#include<stdio.h>

void InsertSort(int *a,int n)//��С����
{
	int i,j,temp;

	for( i = 1; i < n; i++ )//Ĭ�ϵ�һ��������ã��ӵڶ�������ʼ����,����n-1������
	{
		temp = a[i];
		j = i;

		while( j > 0  &&  temp < a[j-1] )//�����������λ���õ�����temp��λ
									//�������ǰ�漴a[0]λ�ã�j�����0,Ȼ���ж�j>0������������ѭ��
		{
			a[j] = a[j-1];//��temp��������
			j--;
		}
		
		a[j] = temp;//�ҵ�temp���е�λ�ò���
	
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

	InsertSort(a,n);


	for( i = 0; i < n; i++ )
		printf("%d	",a[i]);

	getchar();
	getchar();
	return 0;
}