#include<cstdio>
#include<vector>
#include<queue>

using namespace std;

vector<int> G[100];//邻接表
int n,m,inDegree[100];//顶点数，入度

bool topologicalSort()
{
	int num = 0;

	queue<int> q;

	for(int i= 0; i < n; i++)
	{
		if(0 == inDegree[i])//找出所有入度为0的顶点,让其入队
			q.push(i);	
	
	}

	while(!q.empty())//只要队列不为空
	{
		int u = q.front();//取队首元素
		
		
		for(int i = 0; i < G[u].size(); i++)
		{
			int v = G[u][i];//取u的后继节结点
			inDegree[v]--;	//顶点v的入度减一
			if(0 == inDegree[v])//如果入度为0则入队
				q.push(v);

		}
		q.pop();//队首出队列
		num++;//每次出列一次，num加一，即出列数等于到最后队列为空的顶点数
	}


	if(num == n)//如果所有顶点都遍历了，返回true
		return true;
	else//如果不是所有顶点都遍历了，此邻接表必存在环，返回false
		return false;
}

int main()
{
	printf("请输入顶点数跟边数\n");
	scanf("%d %d",&n,&m);

	printf("请输入n条边，不要存在环");
	
	for(i = 0; i < m; i++)
	{
		

	}
	


	return 0;
}