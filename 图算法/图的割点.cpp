/*
	
*/
#include<stdio.h>

int n,m,e[9][9],root,book[10];
int num[9],low[9],flag[9],index;//index��������ʱ����ĵ���

int min(int x, int y)
{
	return x < y ? x : y;
}

/*
	������cur��i�ܵ��������ʱ���low[i]����cur��ʱ�������num[cur]����ôֻҪ���cur�㣬i��ͻز�ȥ��	
*/
void dfs(int cur,int father)
{
	int child=0,i,j;
	
	index++;
	num[cur] = index;//��ǰ�����ʱ���
	low[cur] = index;//��ǰ�����ܷ��ʵ����綥���ʱ������ʼ���Լ�

	for(i = 1; i <=n; i++)
	{
		if(1 == e[cur][i])//���������е�
		{
			if(0 == num[i])//û���ʵĵ�϶�����������
			{	
				child++;
				dfs(i,cur);
				
				//	if(low[i] < low[cur])ʹ�������¼�����ԭ������vc6�޷�����δ֪
				//		low[cur] = low[i];

				
				low[cur] = min(low[cur],low[i]);//���µ�ǰ����cur�ܷ��ʵ�����Сʱ���
												//ÿ��ִ�����ⲽ���Ѿ���ζcur������1��iΪֹ����Сʱ���
				if(cur != root && low[i] >= num[cur])//i�����ܻص�����Сʱ�����cur��ʱ�����
					flag[cur] = 1;
				
				if(cur == root && child == 2)
					flag[cur] = 1;

			
			}
		else if(i!= father)//���i���㱻���ʹ����Ҳ��Ǹ��ף�������Сʱ���
		{	//�Բ����¾�������ʱ�������Ϊ��ʵ�ֲ��������ڵ����Ϊ��������ʱ������ܲ������磬��ֻҪ
		//	if(low[i] < low[cur])
		//		low[cur] = low[i];
			low[cur] = min(low[cur],num[i]);//�����low[i]����i�Ǿ������׵�
		}
		
		}
	
	
	}
}

int main()
{
	int i,j,x,y;

	printf("�����붥������");
	scanf("%d",&n);

	do
	{
		scanf("%d %d",&x,&y);
		e[x][y] = 1;
		e[y][x] = 1;
	
	}while('p' != getchar());

	root = 1;//��1�Ŷ��㿪ʼ����������ȱ���

	dfs(1,root);

	for(i=1;i<=n;i++)
	{
		if(flag[i])
			printf("%d	",i);
	}

	getchar();
	getchar();
	return 0;
}