/*
	2017��10��11��21:50:32
*/
#include<stdio.h>

int n,f[256],sum;

//��ʼ������ǿ�����������Լ�
void init()
{
	int i;
	for(i=1;i<=n;i++)
		f[i] = i;

}

int getf(int v)//��ͣ�����ң�ֱ���ҵ�����,��������ı��
{
	if(f[v] == v)//���v��������
		return f[v];
	else
	{
		f[v] = getf(f[v]);//��ͣ�ݹ飬�ҵ����죬��������ı�Ÿ�f[v]
		return f[v];
	
	}

}

void merge(int v,int u)
{
	int t1,t2;
	t1 = getf(u);
	t2 = getf(v);

	if(t1 != t2)//���v,u�������첻ͬ 
		f[t2] = t1;//����u�Ż��˳v�����죬������ԭu�Ż������Ͳ���ָ���Լ��ˡ� 
	//����ԭ��
	//��u�Ŷ������˳���У�����u��Щ�Ⱥ��������١�˳�㡱����

}

int main()
{
	int i,x,y;

	printf("�����ж��ٸ�ǿ��");
	scanf("%d",&n);

	init();

	do
	{		
		printf("����˭��˭һ���,����p��������");
		scanf("%d %d",&x,&y);
		merge(x,y);
	}while('p' != getchar());
	
	for(i=1;i<=n;i++)
	{
		if(f[i] == i)
			sum++;
	}

	printf("ǿ���Ż���%d��\n",sum);
	getchar();
	getchar();

	return 0;
}
