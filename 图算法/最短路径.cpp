#include<stdio.h>
#define IMPOSSIBLE 999999

int min = 9999999,book[101],n,e[101][101];

void dfs(int cur,int dis)
{
	int i;
	if(dis > min)  return;//����Ѿ��߹���·�̱���С·�̻�����ô��û��Ҫ��������ȥ��
	
	if(cur == n)//�ߵ�n����¼·�߳���
	{
		if(dis < min)//�ҵ�����Сֵ���̵�·�ߣ�������Сֵ
		min = dis;
		return;
	}
	for(i=1;i<=n;i++)
	{
		if(e[cur][i] != IMPOSSIBLE && 0 == book[i] )
		{
			book[i] = 1;
			dfs(i,dis+e[cur][i]);
			book[i] = 0;
		}
	
	}


	return;
}

int main()
{
	int i,j,a,b,c;

	printf("���붥����");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if (i == j)  e[i][j] = 0;
			else e[i][j] = 	IMPOSSIBLE;

	while('p' != getchar())
	{
		printf("������ĵ��ĵ㣬�Լ�Ȩֵ������p����");
		scanf("%d %d %d",&a,&b,&c);
		e[a][b] = c;
		
	}


	book[1] = 1;
	dfs(1,0);
	printf("%d",min);

	getchar();
	getchar();

	return 0;
}