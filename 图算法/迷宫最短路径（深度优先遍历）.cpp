#include<stdio.h>


int m,n,p,q,min = 9999999;//p,qΪ�յ�����,n,mΪ�Թ��ĳ���
int a[256][256],book[256][256];

void dfs(int x,int y,int step)
{	//x�����£�y�����ҡ�����ɵ������
	int next[4][2] = {{0,1},//��
						{1,0},//��
						{0,-1},//��
						{-1,0}};//��

	int tx,ty,k;

	if(x == p && y == q)//�����յ�
	{
		//����в������ٵģ�����min��ֵ
		if(step < min)
			min = step;
		return;
	}

	for(k=0;k<=3;k++)//������һ��
	{
		tx = x + next[k][0];
		ty = y + next[k][1];
		//�ж��Ƿ�Խ��
		if(tx > n || tx<1 || ty > m||ty <1)
			continue;
		//�ж��Ƿ����ϰ�������߹���·
		if(0 == a[tx][ty] && 0 == book[tx][ty])
		{
			book[tx][ty] = 1;//�߹������
			dfs(tx,ty,step+1);//������һ����
			book[tx][ty] = 0;//ÿ�εݹ�������һ���㣬��������·�ߵĲ���

		}
	
	}

	return;
}
int main()
{
	int i,j,startx,starty;

	printf("�������Թ��ĳ��ȸ���ȣ��м��ÿո����\n");
	scanf("%d %d",&n,&m);

	//�����Թ�

	printf("��1��ʾ�ϰ��0��ʾ�յأ������Թ�\n");
	for(i=1;i<=n;i++)
		//printf("\n");
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);

	//���������յ�����

	printf("���������յ�����\n");
	scanf("%d %d %d %d",&startx,&starty,&p,&q);
	
	//����㿪ʼ����

	book[startx][starty] == 1;//�����㣬��ֹ�ظ���
	dfs(startx,starty,0);//��ʼ������Ϊ0

	//������̲���

	printf("��̲���Ϊ��%d\n",min);
	getchar();
	getchar();

	return 0;
}