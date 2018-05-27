#include<stdio.h>
#define  INF 65536

int pre[50];

void dfs(int i)
{
	if(pre[i] == i)
		return;

	dfs(pre[i]);
	printf("%d ",pre[i]);

}

int main()
{
	int n,m,i,j,k,w,min,cur,s;
	int G[50][50],dis[50],flag[50] = {0};

	printf("���붥�����Լ�����");
	scanf("%d %d",&n,&m);

	//��ʼ���ڽӾ���
	for(i = 1; i <= n; i++)
		for(j = 1;j <= n; j++)
			if(i == j)	G[i][j] = 0;
			else		G[i][j] = INF;

	//��ʼ��dis������pre����
	for(i = 1; i <= n; i++)
	{
		dis[i] = G[1][i];
		pre[i] = i;
	}
		

	for(i = 1; i <= m; i++)
	{
		scanf("%d %d %d",&j,&k,&w);
		G[j][k] = w;
	
	}


	//Dijkstra
	for(i = 1; i <= n ; i++)//��ǰ����flag[1] = 1;��ֻ��n-1���ɳ�
	{
		min = INF;
		//�ҵ����˷��ʹ��ģ�ʣ�����������ĵ�
		for(j = 1; j <= n; j++)
		{
			if(flag[j] == 0 && dis[j] < min)
			{
				min = dis[j];
				cur = j;

			}
		
		}

		flag[cur] = 1;
		//pre[cur] = ǰ��;
		//���⣺pre�������¼ǰ�����᲻��ȽϺã�ֻ��Ҫ�ı�һ��
		//������ĵĻ� ������Ҫ֪������ǰ����˭������
		for(j = 1; j <= n; j++)
		{
			if(flag[j] == 0 && G[cur][j] < INF && dis[cur] + G[cur][j] < dis[j])//G[cur][j] < INF �˾������ˣ���ʵû��Ҳ����������
			{												//�ɳڽ׶��ж�flag�Ƿ�Ϊ1,��û�ж���
				dis[j] = dis[cur] + G[cur][j];
				pre[j] = cur; 
				//���⣺pre��������²�����Ϊ̫����ڱ����²�������ô��
				//����Ϊ����޸ģ��ɳڣ������ղ��ҵ���С���Ǹ�ǰ��
			}
		}
	}

	for(i = 1; i<= n; i++)
		printf("%d ",pre[i]);


	scanf("%d",&s);
	dfs(s);
	printf("%d\n",s);
//�޷�֪���յ�����һ�����յ������������

	return 0;
}
