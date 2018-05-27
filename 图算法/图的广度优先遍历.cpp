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
		cur = que[head];//当前正在访问节点的编号，可以说cur永远是head指向那个数（节点编号）
	for(i=1;i<=n;i++)
	{
		if(1 == e[cur][i] && 0 == book[i])//如果两个顶点之间有线且顶点没有走过
		{
			//如果有，则把此节点的编号记录在队列中,并标记此节点
			que[tail] = i;
			book[i] = 1;
			tail++;

		}
		if(tail > n)//如果全部节点遍历完，跳出循环,没有此句照样能进行，只是head会走到跟tail同位置而已
		{
			break;
		}
	}
		head++;//进行下一个节点个遍历
	}
			for(i=1;i<=n;i++)
				printf("%d	",que[i]);
	return;
}
int main()
{
	int i,j,a,b;

	printf("请输入顶点个数");
	scanf("%d",&n);

//初始化邻接矩阵
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			if(i==j)	e[i][j] = 0;
			else	e[i][j] = IMPOSSIBLE;

	while('p' != getchar())
	{
		printf("请输入从哪个顶点到哪,中间用空格隔开，按p结束输入\n");
		scanf("%d %d",&i,&j);
		e[i][j] = 1;
		e[j][i] = 1;//因为这是无向图
	
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