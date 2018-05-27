/*
	此算法用的是模拟树，并没有真正用到指针

*/
#include<stdio.h>

int h[101];
int n;

//将传入的的结点的值交换
void swap(int x,int y)
{
	int t;

	t = h[x];
	h[x] = h[y];
	h[y] = t;

}

void siftdown(int i)//传入一个需要向下调整的结点数编号i，传入1表示从堆顶开始向下调整
{
	int t,flag = 0;
	t=i;

	while( i*2 <= n && 0 == flag)//没到叶结点执行循环
	{
		if(h[i] < h[i*2])//比较左儿子与父亲的大小，大的给t
			t = i*2;
	
			if ( i*2+1 <= n )
		{
			if (  h[t] < h[i*2+1]  )
				t = i*2+1;
		}

		if(i != t)//如果t的值改变了，那就调整一下
		{
			swap(t,i);
			i = t;//进行下一次循环
		}
		else
		flag = 1;//如果t到该到的位置，结束循环
	}

}

//创建堆：
void creat()
{
	int i;
	//从最后一个非叶节点到第一个依次向上调整
	for( i = n/2; i >= 1; i-- )
	{
		siftdown(i);
	
	}


}

void heapsort()
{
	while( n > 1 )//如果树没有只剩一个
	{
		//把最后一个数放到树顶，树的数量减1，从树顶开始调整
		swap(1, n);
		n--;
		siftdown(1);
	}

}

int main()
{

	int i=0, num;

	printf("输入要放入堆中的数，输入p结束\n");

	do
	{
		i++;
		scanf("%d",&h[i]);
		
	}while( 'p' != getchar() );

	i--;//由于用户输入p时也会执行循环，执行结束后i会比预期值高1
	n = i;//用户总共输入了n个数
	num = n;

	creat();
	
	heapsort();

	//输出

	for( i = 1; i <= num; i++)
		printf("%d ",h[i]);

	getchar();
	getchar();
	return 0;
}