#define LOCAL
#include<stdio.h>
#include<math.h>
#include<time.h>

int G[10][10],flag[10][10],n;
int dis[10],dmin[10];
int b[10],min = 9999;//bΪ���㵽���ڵ�����ֵ��b������ֵ��Ϊ����

int seach(int x,int y)
{
	int add = 0,add1 = 0;
	for(int i = 1; i <= n; i++)
	{
		if(dis[i] == x)
		{
			add = i;
		}
		if(dis[i] == y)
		{
			add1 = i;
		}
	
	}

	return abs(add - add1);
}

//�ҵ������еĴ���
int bmax()
{
	int i,j,k;
	//����ͼ���ҵ�i����ڱߵ�j�ľ���
		for(i = 1; i <= n; i++)
		{
			for(j = 1; j <=n; j++)
			{
				if(G[i][j] == 1)
				{
					//����������i��j�ľ��룬
					k = seach(i,j);

					//�������Ѿ�������Ĵ����͸��´˵����b[i]
					 if( k > b[i])
					 {
						b[i] = k;
					 }
				}
			}
		}
		
		//����b[i]���ҵ�����b[i]��Ϊ�����еĴ���
		int max = b[1];

		for(i = 1; i <= n; i++)
		{
			if(b[i] > max)
				max = b[i];
		
		}
		
		//���³�ʼ��b[i]
		for(i = 1; i <= n; i++)
		{
			 b[i] = 0;
		}

		return max;
}

void line(int cur,int sum)
{
	int i;
		
	dis[sum]  = cur;

	if(sum > n)
	{
		
		int max = bmax();

		//�������֪�������е����ȴ���minС�������minֵ�������µõ�minֵ������dmin
		if(max < min)
		{
			min = max;
			for(i = 1; i <= n; i++)
			{
				dmin[i] = dis[i];
			}
			
		}
		return;
	}

	for(i = 1; i <= n; i++)
	{
		//�����ǰ�ڵ㵽i���ߣ�����
		if(G[cur][i] == 1 && flag[cur][i] == 0)
		{	
	
			flag[cur][i] = 1;
			flag[i][cur] = 1;
			line(i,sum+1);
			flag[cur][i] = 0;
			flag[i][cur] = 0;
		}
	
	}


}

int main()
{
	int m,i,j,k;
	//�����ض��򵽴���txt
#ifdef LOCAL
	freopen("����.in","r",stdin);
#endif
	//������ֶ����룬ע�͵�LOCAL�Ķ��壬ִ�����³���
#ifndef LOCAL
	printf("�����붥����������\n");
	printf("Ȼ����������ߵ����\n");
#endif 
	scanf("%d %d",&n,&m);


	for(i = 0; i < m; i++)
	{
		scanf("%d %d",&j,&k);
		G[j][k] = 1;
		G[k][j] = 1;
	}

	line(1,1);

	printf("��С������%d\n",min);
	for(i = 1; i <= n; i++)
	{
		printf("%c ",dmin[i]+'A'-1);
	}
	printf("\n");

	printf("Time used = %.3fs\n",(double)clock() / CLOCKS_PER_SEC);

	return 0;
}