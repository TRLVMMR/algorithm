/*
	�ҳ�����һ������ٵ�·������ӡ����·������̾��룬�����ٻ��� 
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
				//����������ˣ�֮ǰ���볤��ǰ������������� 
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
	
	//���Լ���u�� 
	tempPath.push_back(u);
	
	for(int i = 0; i < pre[u].size(); i++)
	{
		int v = pre[u][i];
		
		//�ҵ�����Ӧ��cost�� �����ڽӾ�������Ҫ�ⲽ (����������ͼ���ſ�����ô��)
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

	freopen("���·���뻨��.in", "r", stdin);
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
		//����ͼ 
		temp.v = u;
		Adj[v].push_back(temp);
	}
	
	Djikstra(s);
	
	mincost = INF;
	DFS(end, 0);
	
	int size = ans.size();
	
	//������� 
	for(int i = size - 1; i > 0; i--)
	{
		cout << ans[i] << "->";
	}
		cout << ans[0] << " ";
	
	cout << dis[end] <<" ";	
	cout << mincost << endl;
	
	
	return 0;
}
