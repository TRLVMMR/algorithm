/*
	����������ȣ�������ȱ��������������б�Ȩֵ��ȵ����
	������2017.10.7
*/
#include<stdio.h>
#define INF 65536

struct note
{
	int x;//���б��
	int s;//ת������
};

int main()
{
	struct note que[256];//que�������ڴ��start���е��������е���Сת������
	int e[51][51] = {0},book[51] = {0};
	int i,j,n,start,end,min,cur,flag=0;
	int head,tail;

	//��ʼ����ά����
	printf("��������и���");
	scanf("%d",&n);

	for(i=1;i<=n;i++)
		for(j=1;j<=n;j++)
			if(i==j) e[i][j] = 0;
			else e[i][j] = INF;

	while('p' != getchar())
	{
		printf("����������ĵ���,����p��������");
		scanf("%d %d",&i,&j);
		if(i <= n && j <= n)
		{
		e[i][j] = 1;
		e[j][i] = 1;//����������ͼ
		}
		else
			printf("���������ֵ̫������������");
	}
	
	head = 1;
	tail = 1;

	printf("���뿪ʼ���и�Ŀ�ĵس��еı�ţ��м��ÿո����");
	scanf("%d %d",&start,&end);


	//��start�ų��г�������start���м������
	que[tail].x = start;
	que[tail].s = 0;
	tail++;
	book[start] = 1;


	while(head < tail)
	{
		cur = que[head].x;//curΪ��ǰ���б��
	//	if(min > note[cur])
	//		min = note[cur];//����Ҫ����Сֵ����Ϊһ��չ��Ŀ����У�que���鴢��Ŀ϶�����Сֵ
		for(i=1;i<=n;i++)
		{
			if(1 == e[cur][i] &&0 == book[i])
			{
				book[i] = 1;
				que[tail].x = i;//������ǰ��ת���ĳ��б�ŷ������
				que[tail].s = que[head].s + 1;//ת��������һ
					tail++;
			}
			if(tail-1 == end)//����ŵ�forѭ����������tail��Զ��
			{
				flag = 1;
				break;
			}
		}

		if(1 == flag)
			break;
			head++;
	}


	printf("��Сת����Ϊ��%d",que[tail-1]);
	return 0;
}