/*
	找出最短且花费最少的路径，打印出此路径，最短距离，跟最少花费 
*/
#include<vector>
#include<iostream>
#include<algorithm>
#define INF 0x3fffffff

using namespace std;

const int maxn = 256;

struct Node
{
	int v;
	int w;
	int cost;
};

int n, m, s, end;
//Node G[maxn][maxn];
vector<Node> Adj[maxn];
vector<int> pre[maxn];
vector<int> tempPath, ans;
 
int dis[maxn];
bool flag[maxn];
int mincost;

void Djikstra(int s)
{
	fill(dis, dis + maxn, INF);
	fill(flag, flag + maxn, false);
	
	dis[s] = 0;
	
	for(int i = 0; i < n; i++)
	{
		int min = INF;
		int u = -1;
		
		for(int j = 0; j < n; j++)
		{
			if(flag[j] == false && dis[j] < min)
			{
				min = dis[j];
				u = j;
			}
		}
		
		if(u == -1)
			return;
		
		flag[u] = true;
		
		int size = Adj[u].size();
		for(int j = 0; j < size; j++)
		{
			int w = Adj[u][j].w;
			int v = Adj[u][j].v;
			
			if(flag[j] == false && dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				//如果距离变短了，之前距离长的前驱，不是这里的 
				pre[v].clear();
				pre[v].push_back(u);
				
			}
			else if(flag[j] == false && dis[u] + w == dis[v])
			{
				pre[v].push_back(u);
			}
			
		}
		
	}
	
	
}


void DFS(int u, int cost)
{
	if(u == s)
	{
		tempPath.push_back(u);
		
		if(mincost >  cost)
		{
			mincost = cost;
			ans = tempPath;
		}
		
		tempPath.pop_back();
		return;
	}
	
	//尝试加入u点 
	tempPath.push_back(u);
	
	for(int i = 0; i < pre[u].size(); i++)
	{
		int v = pre[u][i];
		
		//找到边相应的cost， 若用邻接矩阵，则不需要这步 (由于是无向图，才可以这么找)
		for(int j = 0; j < Adj[u].size(); j++)
		{
			if(Adj[u][j].v == v)
			{
				DFS(v, cost + Adj[u][j].cost);
			}
			
		}
	}
	 
	tempPath.pop_back();
	
	return;
}

int main()
{	

	freopen("最短路径与花费.in", "r", stdin);
	cin >> n >> m >> s >> end;
	
	for(int i = 0; i < m; i++)
	{
		int u, v, w, cost;
		Node temp;	
		
		cin >> u >> v >> w >> cost;
		temp.v = v;
		temp.w = w;
		temp.cost = cost;
		
		Adj[u].push_back(temp);
		//无向图 
		temp.v = u;
		Adj[v].push_back(temp);
	}
	
	Djikstra(s);
	
	mincost = INF;
	DFS(end, 0);
	
	int size = ans.size();
	
	//倒着输出 
	for(int i = size - 1; i > 0; i--)
	{
		cout << ans[i] << "->";
	}
		cout << ans[0] << " ";
	
	cout << dis[end] <<" ";	
	cout << mincost << endl;
	
	
	return 0;
}
