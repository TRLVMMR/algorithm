/*
	���㷨�õ���ģ��������û�������õ�ָ��

*/
#include<stdio.h>

int h[101];
int n;

//������ĵĽ���ֵ����
void swap(int x,int y)
{
	int t;

	t = h[x];
	h[x] = h[y];
	h[y] = t;

}

void siftdown(int i)//����һ����Ҫ���µ����Ľ�������i������1��ʾ�ӶѶ���ʼ���µ���
{
	int t,flag = 0;
	t=i;

	while( i*2 <= n && 0 == flag)//û��Ҷ���ִ��ѭ��
	{
		if(h[i] < h[i*2])//�Ƚ�������븸�׵Ĵ�С����ĸ�t
			t = i*2;
	
			if ( i*2+1 <= n )
		{
			if (  h[t] < h[i*2+1]  )
				t = i*2+1;
		}

		if(i != t)//���t��ֵ�ı��ˣ��Ǿ͵���һ��
		{
			swap(t,i);
			i = t;//������һ��ѭ��
		}
		else
		flag = 1;//���t���õ���λ�ã�����ѭ��
	}

}

//�����ѣ�
void creat()
{
	int i;
	//�����һ����Ҷ�ڵ㵽��һ���������ϵ���
	for( i = n/2; i >= 1; i-- )
	{
		siftdown(i);
	
	}


}

void heapsort()
{
	while( n > 1 )//�����û��ֻʣһ��
	{
		//�����һ�����ŵ�����������������1����������ʼ����
		swap(1, n);
		n--;
		siftdown(1);
	}

}

int main()
{

	int i=0, num;

	printf("����Ҫ������е���������p����\n");

	do
	{
		i++;
		scanf("%d",&h[i]);
		
	}while( 'p' != getchar() );

	i--;//�����û�����pʱҲ��ִ��ѭ����ִ�н�����i���Ԥ��ֵ��1
	n = i;//�û��ܹ�������n����
	num = n;

	creat();
	
	heapsort();

	//���

	for( i = 1; i <= num; i++)
		printf("%d ",h[i]);

	getchar();
	getchar();
	return 0;
}