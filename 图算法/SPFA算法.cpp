#include<stdio.h>
#define INF 65536

int main()
{
	int n,m,i=0,j,k;
	int u[8],v[8],w[8];
	int first[6],next[8];
	int dis[6] = {0},book[6] = {0};
	int que[101] = {0},head = 1,tail = 1;
	
	printf("���붥����\n");
	scanf("%d",&n);

	//��ʼ��dis����
	for(i = 1; i <= n; i++)
		dis[i] = INF;
	dis[1] = 0;

	//��ʼ��book����
	for(i = 1; i <= n; i++)
		book[i] = 0;

	//��ʼ��first�����±�1-nΪ-1����û�б�
	for(i = 1; i <= n; i++)
		first[i] = -1;

	printf("����ߣ����������������Ȩֵ����p��������\n");
	do
	{
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		next[i] = first[u[i]];
		first[u[i]] = i;
	
	}while('p' == getchar());

	return 0;
}