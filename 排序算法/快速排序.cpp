#include<stdio.h>

int a[256];

void quicksort(int left,int right)
{
	int temp,i,j,k;

	if (left > right)
		return;

	temp = a[left];//ȡ����ߵ���Ϊ��׼��
	//��ʼ��i��j��λ�������������λ��
	i = left;
	j = right;

	while( i != j )//����������ģ����i��j��ͬλ�������������ͬλ�ã���λ����׼����λ��
	{
		//������ұ��ȿ�ʼ����Ϊ����ṩ��һ����׼λ���Ƚ��ˣ����������߿�ʼ��ÿ�λ�׼λ����ƫ��
		//��Ϊ�ȿ�ʼ��һ������ռ�����С����󣩵�λ�á� ��ˣ��������߿�ʼ��ÿ�ζ���ѱ���������ӵ�����ߣ����ǲ������ 
		while( i < j && a[j] >= temp )
			j--;
		while( i < j && a[i] <= temp )
			i++;//����i!=j����i<j,i��j�������������ԣ����iһ��С��j�����õ���i>j�������
				//���������i=j����ʱ�������򣬽��н�������

		//������С��������λ�ã��ô�������ұߣ�С�������
	if( i < j )
	{
		k = a[i];
		a[i] = a[j];
		a[j] = k;
	
	}
	}


	//����������û�׼����λ����������λ�����׼��
	a[left] = a[i];
	a[i] = temp;

	quicksort( left, i-1 );
	quicksort( i+1, right );

	return;
}


int main()
{
	int i,n;
	
	printf("������Ҫ����ĸ���");
	scanf("%d",&n);

	printf("������%d���������",n);

	for(i = 1; i <= n; i++)
		scanf("%d",&a[i]);

	quicksort(1,n);

	for(i = 1; i <= n; i++)
		printf("%d	",a[i]);

	getchar();
	getchar();
	return 0;
}
