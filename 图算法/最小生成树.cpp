/*
	�ȰѱߴӴ�С����

	
*/

#include<stdio.h>

struct edge
{
	int u;
	int v;
	int w;
};

struct edge e[10];//�����С����ʵ����������ã�Ҫ��m�����ֵ��1
int n,m;
int f[7] = {0},sum = 0,count = 0;
//f����Ҫ����ʵ����������ã�Ҫ��n�����ֵ��1����Ϊ������0���õ���
//f���������鲢��������

void quicksort(int left,int right)//��С������п�������
{
	int i,j;

	struct edge temp;


	if(left > right)
		return;

	i = left;
	j = right;

	while(i != j)
	{
		while(i < j && e[j].w >= e[left].w)
			j--;
		while(i < j && e[i].w <= e[left].w)
			i++;

		if(i < j)
		{
			temp = e[i];
			e[i] = e[j];
			e[j] = temp;
		}
	}

	//��׼����λ
	//˳���д���ˣ�����tempû��ֵ�������ֹͣ����
	temp = e[left];
	e[left] = e[i];
	e[i] = temp;
	


	quicksort(left,i-1);
	quicksort(i+1,right);

	return;
}

int getf(int v)
{
	if(v == f[v])
		return f[v];
	else
	{
		f[v] = getf(f[v]);
		return f[v];
	}

}

int merge(int u,int v)
{
	int t1,t2;

	t1 = getf(u);
	t2 = getf(v);

	if(t1 != t2)
	{
		f[t2] = t1;
		return 1;
	}
	else
		return 0;

}

int main()
{
	int i = 0;
	
	m = -1;//m����-1�ڽ���ѭ��ʱ�Ż���ڱ���

	printf("�����붥�����");
	scanf("%d",&n);

	do
	{
		i++;
		printf("��������ĵ����Լ�Ȩֵ������p��������");
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
		m++;
	}while('p' != getchar());

	for(i=1;i<=n;i++)//�鲢����ʼ��
		f[i] = i;

	quicksort(1,m);//�������������ҵ������бߴ�С�Ŀ�������
	//���н���ʱ��e�����С����������



	for(i=1;i<=m;i++)
	{
		if( 0 != merge(e[i].u,e[i].v) )//��������߲�����ͨ�ģ�ִ��ѭ��,ִ��merge���Ὣ��������ͨ
		{
			count++;
			sum = sum +e[i].w;
		
		}
		if( n-1 ==  count )
			break;
	}

	printf("%d",sum);


	getchar();
	getchar();

	return 0;
}