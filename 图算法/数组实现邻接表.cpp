/*
	2017年10月9日17:36:15
	稀疏图用邻接表，稠密图用邻接矩阵
	其遍历结果是倒序的
*/
#include<stdio.h>

int main()
{
	int i,n,m,k;
	int u[6],v[6],w[6];//要根据实际情况来设置，比m最大值大1
	int frist[5],next[5];//要根据实际情况设置，比n最大值大1

	scanf("%d %d",&n,&m);

	for(i=1;i<=n;i++)
		frist[i] = -1;



	for(i=1;i<=m;i++)
	{
		printf("请输入从哪到哪以及权值");
		scanf("%d %d %d",u[i],v[i],w[i]);

		next[i] = frist[u[i]];//若第i次要更新first的值，则把这个数据放到next第i次记录的位置
		frist[u[i]] = i;//更新first的值，即第i次读入编号为u[i]的顶点
	
	
	}

	for(i=1;i<=n;i++)
	{//遍历以i为起点的所有边
		k = frist[i];//k的值就是用来寻找next编号的值
		while(k!=-1)
		{
			printf("%d %d %d\n",u[k],v[k],w[k]);
			k = next[k];//把上一次的次数给K，结果使得倒序遍历以i为起点的所有边
		
		}
	
	}


	return 0;
}