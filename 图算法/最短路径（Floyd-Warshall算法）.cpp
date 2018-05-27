/*
	���ģ���i��j������һ��վ����תվ���Ӷ��ҵ����·��	
	����ʱ�䣺2017��10��8��11:36:51
	����ʱ�䣺2017��10��8��11:37:04
*/
#include<stdio.h>
#define INF 65536


int main()
{
	int i,j,k,a,b,c;
	int n,e[51][51];
	
	printf("�����붥����:");
	scanf("%d",&n);

	//��ʼ���ڽӾ���
	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j] = 0;
			else e[i][j] = INF;

	printf("����pֹͣ����\n");

	//�����
	while('p' != getchar())
	{
	printf("���붥�㵽�����Ѽ�Ȩֵ���м��ÿո������");
	scanf("%d %d %d",&a,&b,&c);
	e[a][b] = c;
	}

	//floyd-warshall�㷨������䣺��i�ŵ�j�Ŷ����k����תվ�����·��
	for(k=1;k<=n;k++)
		for(i=1;i<=n;i++)
			for(j=1;j<=n;j++)
				if(e[i][j] > e[i][k] + e[k][j])
					e[i][j] = e[i][k] + e[k][j];

	//������յĽ�������������ӡ����
	for(i =1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			printf("%10d",e[i][j]);//�涨������10���ַ����
		}
		printf("\n");
	}
	return 0;
}