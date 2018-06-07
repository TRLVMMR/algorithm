/*
	0���㵽������̾���Ϊ0 1 5 3 4 6 

*/
#include<stdio.h>
#include<vector>
#include<algorithm>
#define MAXV 256
#define INF 0x3fffffff

using namespace std;

void DFS(int pre[], int s, int v, int d);

struct Node
{
	int v;
	int w;	
};

vector<Node> Adj[MAXV];


void Dijkstra(int s, int n)
{
	int dis[MAXV];
	bool flag[MAXV];//û�����ʣ�flag[i]Ϊtrue������Ϊfalse 
	int pre[MAXV];//��ʼ��ÿ���ڵ�ǰ���ڵ�Ϊ-1 
	fill(dis, dis+MAXV, INF);
	fill(flag, flag+MAXV, true);
	
	for(int i = 0; i < n; i++) 
		pre[i] = i;
		
	dis[s] = 0;
	
	for(int i = 0; i < n; i++)
	{
		int min = INF;
		int u = -1;
		
		for(int j = 0; j < n; j++)
		{
			if(dis[j] < min && flag[j])
			{
				min = dis[j];
				u = j;
			}
		}
		
		//û�ж�����s��ͨ 
		if(u == -1) return;
		flag[u] = false;
		
		for(int j = 0; j < Adj[u].size(); j++)
		{
			int w = Adj[u][j].w;
			int v = Adj[u][j].v;
			
			if(dis[u] + w < dis[v] && flag[v])
			{
				dis[v] = dis[u] + w;
				//vͨ��u���ɳڣ���������u�����·��+u��v������u��v������,�е㶯̬�滮����˵̰�ĵ�ζ�� 
				pre[v] = u;
			//	printf("[%d] = %d\n", v, u);
			}
			
			
		}
		
		
	}

	//��ӡ���нڵ�����·�� 
	for(int i = 0; i < n; i++)
		DFS(pre, s, i, 0);
	
}

void DFS(int pre[], int s, int v, int d)
{
	if(s == v)
	{
		if(d == 0)
		{
			printf("%d\n", s);
			
		}
		else
		{
			printf("%d->", s);
		}
		return;
	}
	
	DFS(pre, s, pre[v], d+1);
	if(d > 0)
		printf("%d->", v);
	else
		printf("%d\n", v);
}

int main()
{
//	vector<Node> Adj[MAXV];
	
	int n, m, s;
	
	freopen("���·������.txt", "r", stdin);
	scanf("%d %d %d", &n, &m, &s);
	
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		
		Node temp;
		temp.v = v;
		temp.w = w;
		Adj[u].push_back(temp);
		
	}
	
	Dijkstra( 0, n);
	
	
	return 0;
}
