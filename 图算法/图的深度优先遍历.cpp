#include<stdio.h>
#define IMPOSSIBLE 65536

int book[256], e[256][256],n,sum;

void dfs(int cur)
{
	int i;//ÿ����һ���ڵ㡣sum�ͼ�1
	//if(cur >= n) return;//���ֵ������ǵ�ǰ���ʶ�����Զ���ᳬ��n

	sum++;

	if(sum >= n) return;
	else
	{
		for(i=0;i<n;i++)
		{
			//����һ�����⣬��2ʱ����0�Ѿ��߹��ˡ�����2-��0����·�����ӡ
			if(1 == e[cur][i] && 0 == book[i] ||  1 == e[i][cur] && 0 == book[i])
			{
			if (1 == e[cur][i] && 0 == book[i])
			{
			
				printf("v%d-->v%d\n",cur,i);
				//��i�ڵ㿪ʼ������һ���ڵ㣬���ջ��˻���
			}
			if(1 == e[i][cur] && 0 == book[i])
			{
			
				printf("v%d<--v%d\n",cur,i);
			}
			book[i] = 1;
			dfs(i);
			}
		}
	}
	return;
}


int main()
{
	int i,j,a,b;

	
	printf("�����붥����:");
	scanf("%d",&n);

	//��ʼ���ڽӾ���
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i==j) e[i][j] = 0;
			else e[i][j] = IMPOSSIBLE;

	//�����ڽӾ���
	printf("����pֹͣ����,");

	while('p' != getchar())
	{
	printf("���붥�㵽���㣬�м��ÿո������");
	scanf("%d %d",&a,&b);
	e[a][b] = 1;
	}

	//������ȱ���
	book[0] = 1;//��ǵ�0�Žڵ����߹�
	dfs(0);//��0�Žڵ㿪ʼ

	getchar();
	getchar();
	return 0;
}