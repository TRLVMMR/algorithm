/*
	num记录某点入队次数→判断是否存在负环（环的和为负数）→方法：num次数大于n-1
	把队首front当中介点,不断循环，每次松弛就将松弛的点入列push
	直到队列为empty
	

*/
#include<stdio.h>
#include<vector>
#include<queue>
#define MAXV 50//最大顶点数

using namespace std;

struct Note
{
	int v,w;//u->v,权值w
};

vector<Note> G[MAXV];//图G，G[u]存放以u出发能到达的所有顶点
int n,m;
int dis[MAXV];

bool SPFA(int s)
{
	queue<int> q;
	static int num[MAXV];
	bool inq[MAXV];

	memset(inq,false,sizeof(inq));

	//源点入队操作
	q.push(s);//将源点入队
	inq[s] = true;//标记源点在队列中
	num[s]++;//标记源点的入队加1

	while( !q.empty() )
	{
		//记录队首顶点，然后将其出列
		int u = q.front();
		q.pop();
		inq[u] = false;

		//遍历所有u点可达的有向边
		for(int j = 0; j < G[u].size(); j++)
		{
			int v = G[u][j].v;
			int w = G[u][j].w;
			
			//更新dis的值
			if(dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;

				//如果v点没在队列中，则加入队列
				if( !inq[v] )
				{
					q.push(v);
					inq[v] = true;
					num[v]++;

					if(num[v] >= n)		return false;//有可达负环
				
				}
			}
		
		
		}

	
	}

	return true;

}

int main()
{
	int i,j,u,v,w;
	Note temp;

	printf("请输入顶点数以及边数：");
	scanf("%d %d",&n,&m);
	
	//初始化邻接表
	printf("请输入从哪到哪以及权值");
	for(i = 0; i < m; i++)
	{
		scanf("%d %d %d",&u,&v,&w);
		temp.v = v;
		temp.w = w;
		G[u].push_back(temp);
	
	}

	return 0;
}