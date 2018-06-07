#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

const int maxn = 256;
const int inf = 0x3fffffff;

struct Node
{
	int v;//目标节点 
	int w;//权值 
};

int n, m;
vector<Node> Adj[maxn];
bool atq[maxn];//记录是否在队列里 
int inq[maxn];//记录入队次数 
int dis[maxn];

bool SPFA(int s)
{
	fill(dis, dis + maxn, inf);
	fill(inq, inq + maxn, 0);
	fill(atq, atq + maxn, false);
	
	queue<int> q;
	q.push(s);
	atq[s] = true;
	inq[s]++; 
	
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		atq[u] = false;
		
		int size = Adj[u].size();
		
		for(int i = 0; i < size; i++)
		{
			int v = Adj[u][i].v;
			int w = Adj[u][i].w;
			
			if(dis[u] + w < dis[v])
			{
				dis[v] = dis[u] + w;
				
				if(!atq[v])
				{	
					q.push(v);
					atq[v] = true;
					inq[v]++;
					
					if(inq[v] >= n)
						return false;
				}
			
				
			}
			
		} 
		
	}
	
	return true;
}


int main()
{
	
	cin >> n >> m;
	
	for(int i = 0; i < m; i++)
	{
		int u, v, w;
		
		cin >> u >> v >> w;
		
		Node temp;
		temp.v = v;
		temp.w = w; 
		
	}
	//输入源点	
	int s;
	cin >> s;
	
	if(SPFA(s))
	{
		
	}
	else
	{
		cout << "输入路径存在负环" << endl; 
	}
	
	
	return 0;
}
