#include<stdio.h>
#define IMPOSSIBLE 65536

static int book[256],e[256][256],que[256],n;
	int head,tail;

void bfs(int cur)
{
	int i;

	tail++;


	//
	while(head < tail)
	{
		cur = que[head];//��ǰ���ڷ��ʽڵ�ı�ţ�����˵cur��Զ��headָ���Ǹ������ڵ��ţ�
	for(i=1;i<=n;i++)
	{
		if(1 == e[cur][i] && 0 == book[i])//�����������֮�������Ҷ���û���߹�
		{
			//����У���Ѵ˽ڵ�ı�ż�¼�ڶ�����,����Ǵ˽ڵ�
			que[tail] = i;
			book[i] = 1;
			tail++;

		}
		if(tail > n)//���ȫ���ڵ�����꣬����ѭ��,û�д˾������ܽ��У�ֻ��head���ߵ���tailͬλ�ö���
		{
			break;
		}
	}
		head++;//������һ���ڵ������
	}
			for(i=1;i<=n;i++)
				printf("%d	",que[i]);
	return;
}
int main()
{
	int i,j,a,b;

	printf("�����붥�����");
	scanf("%d",&n);

//��ʼ���ڽӾ���
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i==j)	e[i][j] = 0;
			else	e[i][j] = IMPOSSIBLE;

	while('p' != getchar())
	{
		printf("��������ĸ����㵽��,�м��ÿո��������p��������\n");
		scanf("%d %d",&i,&j);
		e[i][j] = 1;
		e[j][i] = 1;//��Ϊ��������ͼ
	
	}

	book[1] = 1;
	head = 1;
	tail = 1;
	que[tail] = 1;
	bfs(1);

	getchar();
	getchar();
	return 0;
}