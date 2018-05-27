/*
	先把边从大到小排序

	
*/

#include<stdio.h>

struct edge
{
	int u;
	int v;
	int w;
};

struct edge e[10];//数组大小根据实际情况来设置，要比m的最大值大1
int n,m;
int f[7] = {0},sum = 0,count = 0;
//f数组要根据实际情况捞设置，要比n的最大值大1【因为本书里0不用到】
//f数组用来查并集的数组

void quicksort(int left,int right)//从小到大进行快速排序
{
	int i,j;

	struct edge temp;


	if(left > right)
		return;

	i = left;
	j = right;

	while(i != j)
	{
		while(i < j && e[j].w >= e[left].w)
			j--;
		while(i < j && e[i].w <= e[left].w)
			i++;

		if(i < j)
		{
			temp = e[i];
			e[i] = e[j];
			e[j] = temp;
		}
	}

	//基准数归位
	//顺序别写错了，由于temp没赋值，程序会停止运行
	temp = e[left];
	e[left] = e[i];
	e[i] = temp;
	


	quicksort(left,i-1);
	quicksort(i+1,right);

	return;
}

int getf(int v)
{
	if(v == f[v])
		return f[v];
	else
	{
		f[v] = getf(f[v]);
		return f[v];
	}

}

int merge(int u,int v)
{
	int t1,t2;

	t1 = getf(u);
	t2 = getf(v);

	if(t1 != t2)
	{
		f[t2] = t1;
		return 1;
	}
	else
		return 0;

}

int main()
{
	int i = 0;
	
	m = -1;//m等于-1在结束循环时才会等于边数

	printf("请输入顶点个数");
	scanf("%d",&n);

	do
	{
		i++;
		printf("请输入从哪到哪以及权值，输入p结束输入");
		scanf("%d %d %d",&e[i].u,&e[i].v,&e[i].w);
		m++;
	}while('p' != getchar());

	for(i=1;i<=n;i++)//查并集初始化
		f[i] = i;

	quicksort(1,m);//传入最左与最右的数进行边大小的快速排列
	//排列结束时，e数组从小到大排列着



	for(i=1;i<=m;i++)
	{
		if( 0 != merge(e[i].u,e[i].v) )//如果两条边不是联通的，执行循环,执行merge最后会将两条边联通
		{
			count++;
			sum = sum +e[i].w;
		
		}
		if( n-1 ==  count )
			break;
	}

	printf("%d",sum);


	getchar();
	getchar();

	return 0;
}