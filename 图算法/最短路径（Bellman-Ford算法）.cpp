/*
	���㷨�����ڽ����Ȩ��

	���һ��ͼû�и�Ȩ��·����ô���·���������ı����Ϊn-1������n-1���ɳں����·�����ٷ����仯��
	���n-1�ֺ��Է����仯����ͼ��Ȼ���ڸ�Ȩ��·
*/

#include<stdio.h>
#define INF 65536

int main()
{
	int i=1,k,n,m=-1; 
	int v[10],u[10],w[10],dis[10];//disΪ1��������������·��
	int flag=0,check;

	printf("�����붥�����");
	scanf("%d",&n);

	do 
	{
		printf("�����ĵ��ģ��Լ�Ȩֵ������p����");
		scanf("%d %d %d",&u[i],&v[i],&w[i]);
		
		i++;
		m++;//�洢�ߵ���Ŀ
	}while('p' != getchar());//����pʱ��������scanf��䣬����m++����ִ�У�֮��%d�������ַ��ͣ�����getchar�ӻ����������ܵ�p��Ϣ����
		
	//��ʼ��dis����
	for(i=1;i<=n;i++)
		dis[i] = INF;
		dis[1] = 0;

	//Bellman-Ford������䣺��u[i]->v[i]�����ߵ�����תվ��Ѱ��1�㵽��վ�����·��
	for(k=1;k<=n-1;k++)//���ִ��n-1�Σ����ܶ����б߽����ɳ�
	{
		check = 0;
		for(i=1;i<=m;i++)
			if(dis[v[i]] > dis[u[i]] + w[i])//w[i]Ϊu[i]->v[i]��Ȩֵ��·�̣�
			{
				dis[v[i]] = dis[u[i]] + w[i];
				check = 1;
			}
		if(0 == check)//�������disû�и��£��˳�ѭ��
			break;
	}
	for(i=1;i<=m;i++)
		if(dis[v[i]] > dis[u[i]] + w[i])
			flag = 1;//���ڱ���Ƿ���ڸ�Ȩ��

	if(1 == flag)
			printf("��ͼ���и�Ȩ�ߣ����������·��");
	else
	{
	for(i=1;i<=n;i++)
		printf("%d	",dis[i]);
	}

	getchar();
	getchar();
	return 0;
}